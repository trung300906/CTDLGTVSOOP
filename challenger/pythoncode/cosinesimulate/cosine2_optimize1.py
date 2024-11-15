import numpy as np
from multiprocessing import Pool, cpu_count
from time import time

def vector_norms(features):
    """Tính chuẩn Euclidean cho mỗi vector trong ma trận."""
    return np.linalg.norm(features, axis=1)

def cosine_similarity_task(task):
    """Tính toán cosine similarity cho một cặp (i, j)."""
    i, j, features, norms = task
    dot_product = np.dot(features[i], features[j])
    similarity = dot_product / (norms[i] * norms[j] + 1e-9)
    return i, j, similarity

def compute_cosine_matrix(features, num_workers):
    # Chuyển ma trận để tính toán cosine similarity giữa các cột
    features = np.array(features, dtype=np.float32).T
    num_features = features.shape[0]

    # Tính chuẩn của từng vector (từng cột trong ma trận gốc)
    norms = vector_norms(features)

    # Tạo danh sách các cặp (i, j) chỉ trong tam giác trên (i <= j)
    tasks = [(i, j, features, norms) for i in range(num_features) for j in range(i, num_features)]

    # Khởi tạo ma trận cosine similarity
    cosine_matrix = np.zeros((num_features, num_features), dtype=np.float32)

    # Sử dụng multiprocessing để tính toán các cặp (i, j)
    with Pool(processes=num_workers) as pool:
        results = pool.map(cosine_similarity_task, tasks)

    # Điền kết quả vào ma trận và áp dụng tính chất đối xứng
    for i, j, similarity in results:
        cosine_matrix[i][j] = similarity
        cosine_matrix[j][i] = similarity  # Ma trận đối xứng

    return cosine_matrix

def main(input_file):
    # Đọc dữ liệu từ file đầu vào
    start = time()
    with open(input_file, 'r') as f:
        n, m = map(int, f.readline().strip().split())
        features = [list(map(int, f.readline().strip().split())) for _ in range(n)]
    
    # Tính toán ma trận cosine similarity
    cosine_matrix = compute_cosine_matrix(features, min(24, 8))
    end = time()
    return cosine_matrix, end - start

if __name__ == "__main__":
    output, time_run = main("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/cosinesimulate/input.txt")
    for line in output:
        print(" ".join(f"{value:.4f}" for value in line))
    print(f"Execution Time: {time_run:.4f} seconds")
