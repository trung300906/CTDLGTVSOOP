import random
from time import time
import math
from concurrent.futures import ProcessPoolExecutor
from multiprocessing import Manager

def inner_product(matrix_a, matrix_b):
    return sum(x * y for x, y in zip(matrix_a, matrix_b))

# Helper functions for multi-processing
def process_rows(matrix, rows, start_idx, end_idx, return_dict):
    results = {}
    for i in range(start_idx, end_idx):
        results[i] = [inner_product(matrix[i], matrix[j]) for j in range(i, rows)]
    return_dict[start_idx] = results

def parallel_self_product(matrix, rows, num_workers):
    chunk_size = math.ceil(rows / num_workers)
    with Manager() as manager:
        return_dict = manager.dict()
        futures = []
        
        with ProcessPoolExecutor(max_workers=num_workers) as executor:
            for i in range(0, rows, chunk_size):
                futures.append(executor.submit(process_rows, matrix, rows, i, min(i + chunk_size, rows), return_dict))
            
            for future in futures:
                future.result()  # Ensure all tasks are completed
        
        # Convert the dictionary to a full matrix
        results = [[0] * (rows - i) for i in range(rows)]
        for idx, chunk in return_dict.items():
            for i, similarity in chunk.items():
                results[i] = similarity
        return results

def compute_cosine_matrix(features, num_workers):
    num_features = len(features[0])
    num_products = len(features)
    
    transpose_features = [list(row) for row in zip(*features)]
    
    results = parallel_self_product(transpose_features, num_features, num_workers)
    
    # Initialize cosine similarity matrix
    cosine_matrix = [[0.0] * num_features for _ in range(num_features)]
    
    # Retrieve results and update the symmetric matrix
    for i, similarity in enumerate(results):
        for j, inner_product in enumerate(similarity):
            if results[i][0] == 0 or results[i + j][0] == 0:
                detail_similarity = 0.0
            else:
                detail_similarity = round(inner_product / math.sqrt(results[i][0] * results[i + j][0]), 4)
            cosine_matrix[i][i + j] = detail_similarity
            cosine_matrix[i + j][i] = detail_similarity  # Symmetric matrix

    return cosine_matrix

def main(input_file):
    num_worker = 4
    # Read data from file
    # with open(input_file, 'r') as f:
    #     n, m = map(int, f.readline().strip().split())
    #     features = [list(map(int, f.readline().strip().split())) for _ in range(n)]
    
    n, m = 10, 10
    features = [[_ + _ for _ in range(m)] for _ in range(n)]
    # n, m = 4, 3
    # features = [[3, 4, 1], [2, 4, 5], [4, 4, 2], [4, 5, 6]]
    start = time()
    # Compute cosine similarity matrix
    cosine_matrix = compute_cosine_matrix(features, num_worker)
    end = time()
    return cosine_matrix, end - start

if __name__ == "__main__":
    output, time_run = main("input.txt")
    # Print results to console (if needed)
    # print(output)
    print(time_run)
