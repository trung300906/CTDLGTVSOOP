import random
import time
import math
from concurrent.futures import ThreadPoolExecutor

# Matrix operations
def create_matrix(n, m, min_value=0, max_value=100):
    return [[random.randint(min_value, max_value) for _ in range(m)] for _ in range(n)]

def inner_product(vector_a, vector_b):
    return sum(a * b for a, b in zip(vector_a, vector_b))

def cosine_similarity(vector_a, vector_b):
    return inner_product(vector_a, vector_b) / (math.sqrt(inner_product(vector_a, vector_a) *inner_product(vector_b, vector_b)))

def cosine_similarity_matrix(matrix, rows):
    results = [[0.0] * rows for _ in range(rows)]
    for i in range(rows):
        for j in range(i, rows):
            if i == j:
                results[i][j] = 1.0  # Cosine similarity of the same vector is always 1
            else:
                similarity = cosine_similarity(matrix[i], matrix[j])
                results[i][j] = similarity
                results[j][i] = similarity  # Ensure symmetry
    return results

def print_matrix(matrix):
    for row in matrix:
        print(' '.join(f"{elem:.4f}" for elem in row))

# Helper functions for multi-threaded processing
def process_rows(matrix, rows, results, start_idx, end_idx):
    for i in range(start_idx, end_idx):
        for j in range(i, rows):
            if i == j:
                results[i][j] = 1.0
            else:
                similarity = cosine_similarity(matrix[i], matrix[j])
                results[i][j] = similarity
                results[j][i] = similarity  # Ensure symmetry
    return results

def parallel_cosine_similarity_matrix(matrix, rows, num_threads=4):
    results = [[0.0] * rows for _ in range(rows)]
    chunk_size = math.ceil(rows / num_threads)
    
    with ThreadPoolExecutor(max_workers=num_threads) as executor:
        futures = []
        for i in range(0, rows, chunk_size):
            futures.append(executor.submit(process_rows, matrix, rows, results, i, min(i + chunk_size, rows)))
        
        for future in futures:
            future.result()  # Ensure all tasks are completed
    
    return results

def self_check(result_parallel, result_sequential, rows):
    for i in range(rows):
        for j in range(rows):
            if abs(result_parallel[i][j] - result_sequential[i][j]) > 1e-6:  # Use a tolerance for floating point comparison
                return False
    return True

# Main function
def main(n, m, num_threads=4):
    # Initialize matrix
    matrix = create_matrix(n, m)

    print("The initial grid: ")
    print_matrix(matrix)

    # Sequential computation
    start_time = time.time()
    result_sequential = cosine_similarity_matrix(matrix, n)
    end_time = time.time()
    runtime1 = end_time - start_time
    print("The sequential computation result: ")
    print_matrix(result_sequential)
    

    # Parallel computation
    start_time = time.time()
    result_parallel = parallel_cosine_similarity_matrix(matrix, n, num_threads)
    end_time = time.time()
    runtime2 = end_time - start_time
    print("The parallel computation result: ")
    print_matrix(result_parallel)
    print(f"Sequential computation took {runtime1:.4f} seconds")
    print(f"Parallel computation took {runtime2:.4f} seconds")

    # Check if results are the same
    if self_check(result_parallel, result_sequential, n):
        print("Self-check: The result of the parallel program is the same as the sequential program.")
    else:
        print("Self-check: The result of the parallel program is not the same as the sequential program.")

# Execute the main function
if __name__ == '__main__':
    n = 1000  # Example: number of rows
    m = 1000  # Example: number of columns
    main(n, m, num_threads=8)