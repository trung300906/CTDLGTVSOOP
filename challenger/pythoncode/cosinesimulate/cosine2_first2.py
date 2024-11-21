import threading
from concurrent.futures import ProcessPoolExecutor
import math
import queue
from os import cpu_count
import time
from multiprocessing import Manager

def inner_product(vector_a, vector_b):
    return sum(x * y for x, y in zip(vector_a, vector_b))

def read_matrix(filename, start_row, num_hang, num_cot):
    submatrix = []
    with open(filename, 'r') as f:
        lines = f.readlines()[start_row : start_row + num_hang]
        for line in lines:
            row = list(map(float, line.strip().split()[:num_cot]))
            submatrix.append(row)
    return submatrix

def compute_submatrix_inner_product(vector_a, vector_b):
    return 0 # eddit after
def process_submatrix(inputfile, starthang,sohang, cot):
    submatrix = read_matrix(inputfile, starthang, sohang, cot)
    return compute_submatrix_inner_product(submatrix, submatrix)

def parallel_multiprocess_compute(numworkers, subhang, subcot, hang, cot, inputfiles):
    futures = []
    results = []
    with ProcessPoolExecutor(max_workers=numworkers) as executor:
        for i in range(hang, subhang):
            futures.append(
                executor.submit(process_submatrix, inputfiles, i , min(subhang, hang - i), cot)
            )
        for future in futures:
            results.append(future.result())
    return results

def compute_cosinematrix(numworkers, hang, cot, inputfile):
    # inputfiles = [f"{inputfile}_part_{i}" for i in range(numworkers)] 
    subcot = math.ceil(cot / numworkers)
    subhang = math.ceil(hang / numworkers)
    if subhang < 2: subhang = 2
    return_sub = parallel_multiprocess_compute(numworkers, subhang, subcot, inputfile)
    return return_sub
def MAIN(inputfile = "/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/cosinesimulate/input.txt"):
    numworkers = cpu_count()
    with open(inputfile, 'r') as f:
        hang, cot = map(int, f.readline().strip().split())
    start = time()
    cosine_similarity = compute_cosinematrix(numworkers, hang , cot, inputfile)
    end = time()
    return cosine_similarity , end - start