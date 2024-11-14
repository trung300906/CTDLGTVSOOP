import math
from multiprocessing import Pool
from time import time
def dot_product(vec_a, vec_b):
    # Tính tích vô hướng của hai vector
    return sum(a * b for a, b in zip(vec_a, vec_b))

def vector_norm(vec):
    # Tính độ dài (norm) của vector
    return math.sqrt(sum(x * x for x in vec))

def cosine_similarity(args):
    i, j, features, norms = args
    dot = dot_product(features[i], features[j])
    if norms[i] == 0 or norms[j] == 0:
        return i, j, 0.0  # Tránh chia cho 0 nếu norm bằng 0
    return i, j, dot / (norms[i] * norms[j])

def compute_cosine_matrix(features, num_workers):
    num_features = len(features[0])
    num_products = len(features)
    
    # Chuyển đổi ma trận đặc trưng để mỗi cột là một vector đặc trưng
    transposed_features = [[features[row][col] for row in range(num_products)] for col in range(num_features)]
    
    # Tính norm cho từng vector đặc trưng
    norms = [vector_norm(transposed_features[i]) for i in range(num_features)]
    
    # Khởi tạo ma trận cosine similarity
    cosine_matrix = [[0.0] * num_features for _ in range(num_features)]
    
    # Tạo danh sách các công việc cần thực thi song song
    tasks = [(i, j, transposed_features, norms) for i in range(num_features) for j in range(i, num_features)]
    
    # Sử dụng Pool để thực thi các công việc trong tasks song song
    with Pool(processes = num_workers) as pool:
        results = pool.map(cosine_similarity, tasks)
    
    # Nhận kết quả và cập nhật ma trận đối xứng
    for i, j, similarity in results:
        similarity = round(similarity, 4)
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
    cosine_matrix = compute_cosine_matrix(features, 8)
    end = time()
    return cosine_matrix, end -start

if __name__ == "__main__":
    output, time_run = main("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/cosinesimulate/input.txt")
    # In kết quả ra màn hình console (nếu cần)
    print(time_run)