import math
import multiprocessing as mp
from multiprocessing import Pool

def read_matrix(filename):
    with open(filename, 'r') as f:
        n, m = map(int, f.readline().split())
        matrix = []
        for _ in range(n):
            row = list(map(float, f.readline().split()))
            matrix.append(row)
    return n, m, matrix

def calculate_submatrix_similarity(submatrix1, submatrix2):
    dot_product = sum(a * b for a, b in zip(submatrix1, submatrix2))
    norm1 = math.sqrt(sum(a**2 for a in submatrix1))
    norm2 = math.sqrt(sum(b**2 for b in submatrix2))
    return dot_product / (norm1 * norm2)

def process_chunk(chunk_start, chunk_end, n, m, matrix, result_matrix,submatrix_size):
    for i in range(chunk_start, chunk_end):
        for j in range(i, m):
            submatrix1 = matrix[i:i+submatrix_size]
            submatrix2 = matrix[j:j+submatrix_size]
            similarity = calculate_submatrix_similarity(submatrix1, submatrix2)
            result_matrix[i][j] = similarity
            result_matrix[j][i] = similarity

def main(filename):
    n, m, matrix = read_matrix(filename)
    submatrix_size = int(math.log(n * m))

    # Create a shared memory array for the result matrix
    result_matrix = mp.Array('d', n * m)
    result_matrix = [[result_matrix[i*m+j] for j in range(m)] for i in range(n)]

    # Divide the matrix into chunks for parallel processing
    num_processes = min(mp.cpu_count(), 10)
    chunk_size = n // num_processes

    with Pool(num_processes) as pool:
        jobs = []
        for i in range(num_processes):
            chunk_start = i * chunk_size
            chunk_end = min((i+1) * chunk_size, n)
            job = pool.apply_async(process_chunk, args=(chunk_start, chunk_end, n, m, matrix, result_matrix,submatrix_size))
            jobs.append(job)

        for job in jobs:
            job.get()

    # Print the result matrix
    for row in result_matrix:
        print(' '.join(map('{:.4f}'.format, row)))

if __name__ == '__main__':
    filename = '/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/cosinesimulate/input.txt'  # Replace with your input file name
    main(filename)