import math
from multiprocessing import Pool

# Hàm tính inner product của hai vector
def inner_product(vec1, vec2):
    return sum(v1 * v2 for v1, v2 in zip(vec1, vec2))

# Hàm tính cosine similarity của hai vector
def cosine_similarity(vec1, vec2):
    dot_product = inner_product(vec1, vec2)
    norm1 = math.sqrt(inner_product(vec1, vec1))
    norm2 = math.sqrt(inner_product(vec2, vec2))
    return dot_product / (norm1 * norm2)

# Hàm tính ma trận cosine similarity của một khối
def compute_cosine_similarity(chunk):
    N = len(chunk)
    result = [[0.0 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        for j in range(N):
            result[i][j] = cosine_similarity(chunk[i], chunk[j])
    return result

# Hàm đọc và xử lý dữ liệu trực tiếp từ file
def process_chunk(file_path, chunk_size, start_line, num_lines):
    result_matrix = None
    chunk_lines = []
    
    with open(file_path, 'r') as file:
        lines = file.readlines()[start_line:start_line + num_lines]
        for line in lines:
            chunk_lines.append([float(x) for x in line.strip().split()])
            if len(chunk_lines) == chunk_size:
                chunk_result = compute_cosine_similarity(chunk_lines)
                if result_matrix is None:
                    result_matrix = chunk_result
                else:
                    for i in range(chunk_size):
                        for j in range(chunk_size):
                            result_matrix[i][j] += chunk_result[i][j]
                chunk_lines = []
        if chunk_lines:
            chunk_result = compute_cosine_similarity(chunk_lines)
            if result_matrix is None:
                result_matrix = chunk_result
            else:
                for i in range(len(chunk_lines)):
                    for j in range(len(chunk_lines)):
                        result_matrix[i][j] += chunk_result[i][j]
    return result_matrix

# Hàm chính để chia ma trận và xử lý song song
def main(file_path, processes):
    with open(file_path, 'r') as file:
        first_line = file.readline().strip().split()
        N = int(first_line[0])
        M = int(first_line[1])
    
    chunk_size = int(math.log(N * M))
    num_lines = chunk_size  # Số dòng cho mỗi chunk
    total_lines = N
    lines_per_process = total_lines // processes
    chunks = []
    start_line = 1  # Bắt đầu đọc từ dòng thứ hai vì dòng đầu tiên chứa kích thước ma trận
    
    for i in range(processes):
        chunks.append((file_path, chunk_size, start_line + i * lines_per_process, lines_per_process))
    
    pool = Pool(processes)
    result_matrix = pool.starmap(process_chunk, chunks)
    pool.close()
    pool.join()
    
    # Gộp kết quả từ các chunk
    final_matrix = [[0.0 for _ in range(chunk_size)] for _ in range(chunk_size)]
    for matrix in result_matrix:
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                final_matrix[i][j] += matrix[i][j]
    
    return final_matrix

# Đường dẫn đến file dữ liệu
file_path = 'data.txt'

# Số lượng tiến trình song song
processes = 8

# Gọi hàm chính và in kết quả
result = main(file_path, processes)
for row in result:
    print(" ".join(f"{value:.4f}" for value in row))
