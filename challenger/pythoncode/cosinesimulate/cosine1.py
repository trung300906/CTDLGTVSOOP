import numpy as np
import concurrent.futures
import os
import asyncio
from joblib import Parallel, delayed

# Hàm tính dot product sử dụng bitwise
def bitwise_dot_product(vec1, vec2):
    return sum((x & 0xFFFFFFFF) * (y & 0xFFFFFFFF) for x, y in zip(vec1, vec2))

# Hàm tính norm sử dụng bitwise
def bitwise_norm(vec):
    return sum((x & 0xFFFFFFFF) * (x & 0xFFFFFFFF) for x in vec) ** 0.5

# Hàm tính cosine similarity
def cosine_similarity(vec1, vec2):
    dot_product = bitwise_dot_product(vec1, vec2)
    norm_vec1 = bitwise_norm(vec1)
    norm_vec2 = bitwise_norm(vec2)
    return dot_product / (norm_vec1 * norm_vec2)

# Hàm tính ma trận cosine similarity sử dụng joblib để song song hóa
def cosine_similarity_matrix(features):
    num_features = features.shape[1]
    similarity_matrix = np.zeros((num_features, num_features))
    results = Parallel(n_jobs=os.cpu_count())(
        delayed(cosine_similarity)(features[:, i], features[:, j]) for i in range(num_features) for j in range(i, num_features)
    )
    idx = 0
    for i in range(num_features):
        for j in range(i, num_features):
            similarity_matrix[i, j] = results[idx]
            similarity_matrix[j, i] = results[idx]
            idx += 1
    return similarity_matrix

# Hàm async để thực hiện tính toán đồng thời
async def compute_similarity_async(features, similarity_matrix):
    loop = asyncio.get_event_loop()
    tasks = []
    num_features = features.shape[1]
    for i in range(num_features):
        for j in range(i, num_features):
            tasks.append(loop.run_in_executor(None, cosine_similarity, features[:, i], features[:, j]))
    results = await asyncio.gather(*tasks)
    idx = 0
    for i in range(num_features):
        for j in range(i, num_features):
            similarity_matrix[i, j] = similarity_matrix[j, i] = round(results[idx], 4)
            idx += 1

# Hàm tính ma trận cosine similarity
def compute_similarity(features):
    num_features = features.shape[1]
    similarity_matrix = np.zeros((num_features, num_features))
    loop = asyncio.get_event_loop()
    loop.run_until_complete(compute_similarity_async(features, similarity_matrix))
    return similarity_matrix

# Hàm chính để đọc dữ liệu và tính toán ma trận cosine similarity
def MAIN(input_file):
    with open(input_file, "r") as file:
        data = file.readlines()
    
    first_line = data[0].strip().split()
    N = int(first_line[0])
    M = int(first_line[1])
    
    features = []
    for line in data[1:N + 1]:
        features.append([int(x) for x in line.strip().split()])
    
    features = np.array(features)
    similarity_matrix = compute_similarity(features)
    
    return similarity_matrix

# Sử dụng hàm MAIN để tính toán ma trận cosine similarity
if __name__ == "__main__":
    similarity_matrix = MAIN("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/cosinesimulate/input.txt")
    for row in similarity_matrix:
        print(" ".join(f"{value:.4f}" for value in row))
