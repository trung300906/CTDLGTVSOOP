import numpy as np
import math
from multiprocessing import Pool

# Hàm tính inner product của hai vector
def inner_product(vec1, vec2):
    return np.dot(vec1, vec2)

# Hàm tính ma trận cosine similarity của một khối
def compute_cosine_similarity(chunk):
    N, _ = chunk.shape
    result = np.zeros((N, N))
    for i in range(N):
        for j in range(N):
            result[i, j] = inner_product(chunk[i], chunk[j]) / (np.linalg.norm(chunk[i]) * np.linalg.norm(chunk[j]))
    return result

# Hàm đọc và xử lý dữ liệu trực tiếp từ file
def process_chunk(file_path, chunk_size):
    result_matrix = None
    with open(file_path, 'r') as file:
        lines = file.readlines()
        chunk_lines = []
        for line in lines:
            chunk_lines.append([float(x) for x in line.strip().split()])
            if len(chunk_lines) == chunk_size:
                chunk = np.array(chunk_lines)
                chunk_result = compute_cosine_similarity(chunk)
                if result_matrix is None:
                    result_matrix = chunk_result
                else:
                    result_matrix += chunk_result
                chunk_lines = []
        if chunk_lines:
            chunk = np.array(chunk_lines)
            chunk_result = compute_cosine_similarity(chunk)
            if result_matrix is None:
                result_matrix = chunk_result
            else:
                result_matrix += chunk_result
    return result_matrix

# Hàm chính để chia ma trận và xử lý song song
def main(file_path, processes):
    with open(file_path, 'r') as file:
        first_line = file.readline().strip().split()
        N = int(first_line[0])
        M = int(first_line[1])
    
    chunk_size = int(math.log(N * M))
    pool = Pool(processes)
    result_matrix = pool.starmap(process_chunk, [(file_path, chunk_size) for _ in range(processes)])
    pool.close()
    pool.join()
    result_matrix = np.sum(result_matrix, axis=0)
    
    return result_matrix

# Đường dẫn đến file dữ liệu
file_path = '/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/cosinesimulate/input.txt'

# Số lượng tiến trình song song
processes = 4

# Gọi hàm chính và in kết quả
result = main(file_path, processes)
print(np.round(result, 4))
