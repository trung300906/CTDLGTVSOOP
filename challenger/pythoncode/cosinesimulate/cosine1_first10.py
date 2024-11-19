import math
from multiprocessing import Pool, Manager

# Hàm tính inner product của hai vector
def inner_product(vec1, vec2):
    return sum(v1 * v2 for v1, v2 in zip(vec1, vec2))

# Hàm tính cosine similarity của hai vector
def cosine_similarity(vec1, vec2):
    dot_product = inner_product(vec1, vec2)
    norm1 = math.sqrt(inner_product(vec1, vec1))
    norm2 = math.sqrt(inner_product(vec2, vec2))
    if norm1 == 0 or norm2 == 0:
        return 0.0
    return dot_product / (norm1 * norm2)

# Hàm tính ma trận cosine similarity của một khối
def compute_cosine_similarity(chunk):
    N = len(chunk)
    result = [[0.0 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        for j in range(N):
            result[i][j] = cosine_similarity(chunk[i], chunk[j])
    return result

# Hàm đọc và xử lý dữ liệu trực tiếp từ file và cập nhật ma trận kết quả
def process_chunk(file_path, chunk_size, start_line, num_lines, result_matrix, lock):
    chunk_lines = []
    with open(file_path, 'r') as file:
        for i, line in enumerate(file):
            if i < start_line:
                continue
            if i >= start_line + num_lines:
                break
            chunk_lines.append([float(x) for x in line.strip().split()])
            if len(chunk_lines) == chunk_size:
                chunk_result = compute_cosine_similarity(chunk_lines)
                with lock:
                    for r in range(chunk_size):
                        for c in range(chunk_size):
                            result_matrix[r][c] += chunk_result[r][c]
                chunk_lines = []
        if chunk_lines:
            chunk_result = compute_cosine_similarity(chunk_lines)
            with lock:
                for r in range(len(chunk_lines)):
                    for c in range(len(chunk_lines)):
                        result_matrix[r][c] += chunk_result[r][c]

# Hàm chính để chia ma trận và xử lý song song
def main(file_path, processes):
    with open(file_path, 'r') as file:
        first_line = file.readline().strip().split()
        N = int(first_line[0])
        M = int(first_line[1])
    
    chunk_size = int(math.log(N * M))
    if chunk_size > N:
        chunk_size = N
    if chunk_size > M:
        chunk_size = M
    total_chunks = N // chunk_size
    num_lines = chunk_size
    start_line = 1
    
    manager = Manager()
    result_matrix = manager.list([[0.0 for _ in range(N)] for _ in range(N)])
    lock = manager.Lock()
    
    chunks = [(file_path, chunk_size, start_line + i * chunk_size, chunk_size, result_matrix, lock) for i in range(total_chunks)]
    
    pool = Pool(processes)
    pool.starmap(process_chunk, chunks)
    pool.close()
    pool.join()
    
    return result_matrix

# Đường dẫn đến file dữ liệu
file_path = '/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/cosinesimulate/input.txt'

# Số lượng tiến trình song song
processes = 8

# Gọi hàm chính và in kết quả
result = main(file_path, processes)
for row in result:
    print(" ".join(f"{value:.4f}" for value in row))
