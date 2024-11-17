import random
import time
import math
from concurrent.futures import ThreadPoolExecutor, ProcessPoolExecutor
import joblib

# Matrix operations
def create_matrix(n, m, min_value=0, max_value=100):
    matrix = [[random.randint(min_value, max_value) for _ in range(m)] for _ in range(n)] 
    return matrix

def inner_product(matrix_a, matrix_b, m):
    return sum(matrix_a[i] * matrix_b[i] for i in range(m))

def self_product(matrix, rows, m):
    results = [[0] * (rows - i - 1) for i in range(rows - 1)]
    for i in range(rows - 1):
        for j in range(i + 1, rows):
            results[i][j - i - 1] = inner_product(matrix[i], matrix[j], m)
    return results

def print_matrix(matrix):
    for row in matrix:
        print(' '.join(f"{elem:.2f}" for elem in row))
        
# Helper functions for multi-threaded processing
def process_rows(matrix_a, matrix_b, rows, m, results, start_idx, end_idx):
    for i in range(start_idx, end_idx):
        for j in range(i + 1, rows):
            results[i][j - i - 1] = inner_product(matrix_a[i], matrix_b[j], m)
    return results

def parallel_self_product(matrix, rows, m, num_threads=4):
    results = [[0] * (rows - i - 1) for i in range(rows - 1)]
    chunk_size = math.ceil((rows - 1) / num_threads)
    
    with ThreadPoolExecutor(max_workers=num_threads) as executor:
        futures = []
        for i in range(0, rows - 1, chunk_size):
            futures.append(executor.submit(process_rows, matrix, matrix, rows, m, results, i, min(i + chunk_size, rows - 1)))
        
        for future in futures:
            future.result()  # Ensure all tasks are completed
    
    return results

def sequential_self_product(matrix, rows, m):
    return self_product(matrix, rows, m)

def self_check(final_result, final_result_copy, n):
    for i in range(n - 1):
        for j in range(n - i - 1):
            if final_result[i][j] != final_result_copy[i][j]:
                return False
    return True

# Main function
def main(n, m, num_threads=4):
    # Initialize matrices
    matrix_a = create_matrix(n, m)
    matrix_b = create_matrix(n, m)

    print("The initial grid: ")
    print_matrix(matrix_a)

    # Sequential computation
    final_result_copy = sequential_self_product(matrix_a, n, m)
    print("The sequential computation result: ")
    print_matrix(final_result_copy)

    # Parallel computation
    final_result = parallel_self_product(matrix_a, n, m, num_threads)
    print("The parallel computation result: ")
    print_matrix(final_result)

    # Check if results are same
    if self_check(final_result, final_result_copy, n):
        print("Self-check: The result of parallel program is the same as sequential program.")
    else:
        print("Self-check: The result of parallel program is not the same as sequential program.")

# Execute the main function
if __name__ == '__main__':
    n = 4  # Example: number of rows
    m = 3  # Example: number of columns
    main(n, m, num_threads=4)