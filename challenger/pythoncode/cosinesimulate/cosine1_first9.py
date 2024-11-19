import random
from time import time
import math
from concurrent.futures import ProcessPoolExecutor
from multiprocessing import Manager
from os import cpu_count

def inner_product(vector_a, vector_b):
    return sum(x * y for x, y in zip(vector_a, vector_b))

# Helper functions for multi-processing
def process_rows(matrix, rows, start_idx, end_idx, return_dict):
    for i in range(start_idx, end_idx):
        return_dict[i] = [inner_product(matrix[i], matrix[j]) for j in range(i, rows)]

def parallel_inner_product(matrix, rows, num_workers):
    chunk_size = math.ceil(rows / num_workers)
    with Manager() as manager:
        return_dict = manager.list([[] for _ in range(rows)])
        futures = []
        
        with ProcessPoolExecutor(max_workers=num_workers) as executor:
            for i in range(0, rows, chunk_size):
                futures.append(executor.submit(process_rows, matrix, rows, i, min(i + chunk_size, rows), return_dict))
            
            for future in futures:
                future.result()  # Ensure all tasks are completed
        
        return list(return_dict)

def compute_cosine_matrix(features, num_workers):
    num_features = len(features[0])
    num_products = len(features)
    
    transpose_features = [list(row) for row in zip(*features)]
    
    return_dict = parallel_inner_product(transpose_features, num_features, num_workers)
    
    cosine_matrix = [
        [
            round(return_dict[min(i, j)][max(i, j) - min(i, j)] / math.sqrt(return_dict[min(i, j)][0] * return_dict[max(i, j)][0]), 4)
            if (return_dict[min(i, j)][0] != 0 and return_dict[max(i, j)][0] != 0) else 0
            for j in range(num_features)
        ]
        for i in range(num_features)
    ]

    return cosine_matrix

def main(input_file):
    num_worker = cpu_count()*2
    # Read data from file
    with open(input_file, 'r') as f:
        n, m = map(int, f.readline().strip().split())
        features = [list(map(int, f.readline().strip().split())) for _ in range(n)]
    
    #n, m = 3000, 1000
    #features = [[_ + _ for _ in range(m)] for _ in range(n)]
#     n, m = 4, 3
#     features = [[3, 4, 1], [2, 4, 5], [4, 4, 2], [4, 5, 6]]
    start = time()
    # Compute cosine similarity matrix
    cosine_matrix = compute_cosine_matrix(features, num_worker)
    end = time()
    return cosine_matrix, end - start

if __name__ == "__main__":
    output, time_run = main("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/cosinesimulate/input.txt")
    # Print results to console (if needed)
    print(output)
    print(time_run)