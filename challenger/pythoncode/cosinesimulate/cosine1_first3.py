import math
import multiprocessing
import concurrent.futures
import collections
from time import time

def dot_product(vec_a, vec_b):
    # Tính tích vô hướng của hai vector
    return sum(a * b for a, b in zip(vec_a, vec_b))

def vector_norm(vec):
    # Tính độ dài (norm) của vector
    return math.sqrt(sum(x * x for x in vec))

def cosine_similarity(i, j, normalized_features):
    # Tính cosine similarity giữa vector đặc trưng i và j
    return dot_product(normalized_features[i], normalized_features[j])

def compute_cosine_row(args):
    i, normalized_features = args
    num_features = len(normalized_features)
    row_similarities = []
    for j in range(i, num_features):
        similarity = cosine_similarity(i, j, normalized_features)
        row_similarities.append((i, j, similarity))
    return row_similarities
    
def normalize_column(features, index):
    # Lấy cột (vector đặc trưng) và tính norm
    column = [row[index] for row in features]
    norm = vector_norm(column)
    
    # Chuẩn hóa cột bằng norm
    return [(feature / norm if norm != 0 else 0) for feature in column]
    
def compute_normalized_features(features, num_workers):
    num_features = len(features[0])
    
    # Sử dụng ThreadPoolExecutor để tính toán chuẩn hóa cho từng cột
    with concurrent.futures.ThreadPoolExecutor(max_workers=num_workers) as executor:
        # Normalize từng cột song song
        normalized_features = list(executor.map(lambda i: normalize_column(features, i), range(num_features)))
    
    return normalized_features

def compute_cosine_matrix(features, num_workers):
    num_features = len(features[0])
    num_products = len(features)
    
    normalized_features = compute_normalized_features(features, num_workers)
    print("Done normalize features!")
    
    # Khởi tạo ma trận cosine similarity
    cosine_matrix = [[0.0] * num_features for _ in range(num_features)]
    
    # Tạo danh sách các công việc cần thực thi song song
    tasks = [(i, normalized_features) for i in range(num_features)]
    
    # Sử dụng Pool để thực thi các công việc trong tasks song song
    with concurrent.futures.ThreadPoolExecutor(max_workers = num_workers) as executor:
        results = list(executor.map(compute_cosine_row, tasks))
        
    print("Done results!")

    # Nhận kết quả và cập nhật ma trận đối xứng
    for similarity in results:
        for i, j, detail_similarity in similarity:
            detail_similarity = round(detail_similarity, 4)
            cosine_matrix[i][j] = detail_similarity
            cosine_matrix[j][i] = detail_similarity  # Ma trận đối xứng

    return cosine_matrix

def main(input_file):
    features = collections.defaultdict(list)

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
    # Tính ma trận cosine similarity
    cosine_matrix = compute_cosine_matrix(features, 8)
    end = time()
    return cosine_matrix, end - start

if __name__ == "__main__":
    output, time_run = main("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/cosinesimulate/input.txt")
    # In kết quả ra màn hình console (nếu cần)
    # print(output)
    print(time_run)