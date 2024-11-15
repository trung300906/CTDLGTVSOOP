import numpy as np
from joblib import Parallel, delayed
import os
from time import time

# Hàm tính cosine similarity
def cosine_similarity(vec1, vec2):
    dot_product = np.dot(vec1, vec2)
    norm_vec1 = np.linalg.norm(vec1)
    norm_vec2 = np.linalg.norm(vec2)
    if norm_vec1 == 0 or norm_vec2 == 0:
        return 0.0  # Tránh chia cho 0
    return dot_product / (norm_vec1 * norm_vec2)

# Hàm tính toán cho từng cặp (i, j)
def compute_pair(i, j, features):
    vec1 = features[:, i]
    vec2 = features[:, j]
    return i, j, cosine_similarity(vec1, vec2)

# Hàm tính ma trận cosine similarity sử dụng joblib
def cosine_similarity_matrix(features, num_workers):
    num_features = features.shape[1]
    similarity_matrix = np.zeros((num_features, num_features))
    
    results = Parallel(n_jobs=num_workers)(delayed(compute_pair)(i, j, features) for i in range(num_features) for j in range(i, num_features))
    
    for i, j, similarity in results:
        similarity = round(similarity, 4)
        similarity_matrix[i, j] = similarity_matrix[j, i] = similarity
    
    return similarity_matrix

# Hàm chính để đọc dữ liệu và tính toán ma trận cosine similarity
def MAIN(input_file):
    with open(input_file, "r") as file:
        data = file.readlines()

    first_line = data[0].strip().split()
    N = int(first_line[0])
    M = int(first_line[1])
    
    features = np.zeros((N, M), dtype=int)
    
    for idx, line in enumerate(data[1:N + 1]):
        features[idx, :] = np.array(list(map(int, line.strip().split())))
    
    start = time()
    similarity_matrix = cosine_similarity_matrix(features, num_workers=os.cpu_count())
    end = time()
    return similarity_matrix, end - start

# Sử dụng hàm MAIN để tính toán ma trận cosine similarity
if __name__ == "__main__":
    similarity_matrix, time_run = MAIN("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/cosinesimulate/input.txt")
    for row in similarity_matrix:
        print(" ".join(f"{value:.4f}" for value in row))
    print(time_run, "seconds")
