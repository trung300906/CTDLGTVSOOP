import math
from concurrent.futures import ThreadPoolExecutor, as_completed
from multiprocessing import Manager
from time import time
def dot_product(vec_a, vec_b):
    # Tính tích vô hướng của hai vector
    return sum(a * b for a, b in zip(vec_a, vec_b))

def vector_norm(vec):
    # Tính độ dài (norm) của vector
    return math.sqrt(sum(x * x for x in vec))

def cosine_similarity(i, j, features, norms):
    # Tính cosine similarity cho cặp đặc trưng (i, j)
    dot = dot_product(features[i], features[j])
    if norms[i] == 0 or norms[j] == 0:
        return 0.0  # Tránh chia cho 0 nếu norm bằng 0
    return dot / (norms[i] * norms[j])

def compute_cosine_matrix(features):
    num_features = len(features[0])
    num_products = len(features)
    
    # Chuyển đổi ma trận đặc trưng để mỗi cột là một vector đặc trưng
    transposed_features = [[features[row][col] for row in range(num_products)] for col in range(num_features)]
    
    # Tính norm cho từng vector đặc trưng
    norms = [vector_norm(transposed_features[i]) for i in range(num_features)]
    
    # Khởi tạo ma trận cosine similarity
    cosine_matrix = [[0.0] * num_features for _ in range(num_features)]
    
    # Sử dụng ThreadPoolExecutor để giảm overhead của ProcessPoolExecutor
    with ThreadPoolExecutor() as executor:
        futures = []
        
        # Chỉ tính cho các cặp (i, j) với i <= j để giảm số lượng tính toán
        for i in range(num_features):
            for j in range(i, num_features):
                futures.append((i, j, executor.submit(cosine_similarity, i, j, transposed_features, norms)))
        
        # Nhận kết quả và cập nhật ma trận đối xứng
        for i, j, future in futures:
            similarity = round(future.result(), 4)
            cosine_matrix[i][j] = similarity
            cosine_matrix[j][i] = similarity  # Ma trận đối xứng

    return cosine_matrix

def main(input_file):
    # Đọc dữ liệu từ file
    with open(input_file, 'r') as f:
        n, m = map(int, f.readline().strip().split())
        features = [list(map(int, f.readline().strip().split())) for _ in range(n)]
    start = time()
    # Tính ma trận cosine similarity
    cosine_matrix = compute_cosine_matrix(features)
    end = time()
    return cosine_matrix, end -start

if __name__ == "__main__":
    output, time_run = main("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/cosinesimulate/input.txt")
    # In kết quả ra màn hình console (nếu cần)
    print(time_run)
