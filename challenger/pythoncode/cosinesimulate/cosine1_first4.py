import math
import collections
from time import time
from joblib import Parallel, delayed
from multiprocessing import Pool

def dot_product(vec_a, vec_b):
    return sum(a * b for a, b in zip(vec_a, vec_b))

def vector_norm(vec):
    return math.sqrt(sum(x * x for x in vec))

def cosine_similarity(vec_a, vec_b):
    dot_prod = dot_product(vec_a, vec_b)
    norm_a = vector_norm(vec_a)
    norm_b = vector_norm(vec_b)
    if norm_a == 0 or norm_b == 0:
        return 0.0
    return dot_prod / (norm_a * norm_b)

def compute_cosine_row(i, features):
    row_similarities = []
    for j in range(i, len(features)):
        similarity = cosine_similarity(features[i], features[j])
        row_similarities.append((i, j, similarity))
    return row_similarities

def normalize_column(features, index):
    column = [row[index] for row in features]
    norm = vector_norm(column)
    return [(feature / norm if norm != 0 else 0) for feature in column]

def compute_normalized_features(features, num_workers):
    num_features = len(features[0])
    normalized_features = []
    
    with Pool(num_workers) as pool:
        columns = pool.starmap(normalize_column, [(features, i) for i in range(num_features)])
    
    # Transpose normalized columns back to the row-major format
    normalized_features = list(zip(*columns))
    
    return normalized_features

def compute_cosine_matrix(features, num_workers):
    num_features = len(features[0])
    
    normalized_features = compute_normalized_features(features, num_workers)
    print("Done normalize features!")
    
    cosine_matrix = [[0.0] * num_features for _ in range(num_features)]
    
    results = Parallel(n_jobs=num_workers)(delayed(compute_cosine_row)(i, normalized_features) for i in range(num_features))
    
    print("Done results!")
    
    for similarity in results:
        for i, j, detail_similarity in similarity:
            detail_similarity = round(detail_similarity, 4)
            cosine_matrix[i][j] = detail_similarity
            cosine_matrix[j][i] = detail_similarity

    return cosine_matrix

def main(input_file):
    features = []

    with open(input_file, "r") as file:
        data = file.readlines()

    first_line = data[0].strip().split()
    N = int(first_line[0])
    M = int(first_line[1])
    
    for line in data[1:N + 1]:
        features.append([int(value) for value in line.strip().split()])
    
    start = time()
    cosine_matrix = compute_cosine_matrix(features, 8)
    end = time()
    return cosine_matrix, end - start

if __name__ == "__main__":
    output, time_run = main("D:\\code\\CTDLGTVSOOP\\challenger\\pythoncode\\cosinesimulate\\input.txt")
    print(time_run)
