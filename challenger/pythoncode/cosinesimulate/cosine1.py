import concurrent.futures
import os
import math
from collections import defaultdict
from time import time

# Hàm tính dot product sử dụng bitwise
def bitwise_dot_product(vec1, vec2):
    return sum((x & 0xFFFFFFFF) * (y & 0xFFFFFFFF) for x, y in zip(vec1, vec2))

# Hàm tính norm sử dụng bitwise
def bitwise_norm(vec):
    return math.sqrt(sum((x & 0xFFFFFFFF) * (x & 0xFFFFFFFF) for x in vec))

# Hàm tính cosine similarity
def cosine_similarity(vec1, vec2):
    dot_product = bitwise_dot_product(vec1, vec2)
    norm_vec1 = bitwise_norm(vec1)
    norm_vec2 = bitwise_norm(vec2)
    if norm_vec1 == 0 or norm_vec2 == 0:
        return 0.0  # Tránh chia cho 0
    return dot_product / (norm_vec1 * norm_vec2)

# Hàm tính ma trận cosine similarity sử dụng multiprocessing
def cosine_similarity_matrix(features):
    num_features = len(features[0])
    similarity_matrix = [[0.0 for _ in range(num_features)] for _ in range(num_features)]

    # Sử dụng concurrent.futures để tính toán song song với ProcessPoolExecutor
    with concurrent.futures.ProcessPoolExecutor(max_workers=os.cpu_count()) as executor:
        future_to_index = {(i, j): executor.submit(cosine_similarity, [row[i] for row in features], [row[j] for row in features]) 
                           for i in range(num_features) for j in range(i, num_features)}

        for (i, j), future in future_to_index.items():
            result = future.result()
            similarity_matrix[i][j] = similarity_matrix[j][i] = round(result, 4)
    
    return similarity_matrix

# Hàm chính để đọc dữ liệu và tính toán ma trận cosine similarity
def MAIN(input_file):
    features = defaultdict(list)

    # Đọc dữ liệu từ file và lưu vào defaultdict
    with open(input_file, "r") as file:
        data = file.readlines()

    first_line = data[0].strip().split()
    N = int(first_line[0])
    M = int(first_line[1])
    
    for line in data[1:N + 1]:
        for idx, value in enumerate(line.strip().split()):
            features[idx].append(int(value))
    
    # Chuyển đổi defaultdict sang danh sách
    features = [features[i] for i in range(M)]
    
    start = time()
    similarity_matrix = cosine_similarity_matrix(features)
    end = time()
    return similarity_matrix, end - start

# Sử dụng hàm MAIN để tính toán ma trận cosine similarity
if __name__ == "__main__":
    similarity_matrix, time_run = MAIN("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/cosinesimulate/input.txt")
    #for row in similarity_matrix:
        #print(" ".join(f"{value:.4f}" for value in row))
    print(time_run, "seconds")
