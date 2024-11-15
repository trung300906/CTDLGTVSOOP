import numpy as np
from multiprocessing import Pool, cpu_count
from time import time

def vector_norms(features):
    """Calculate Euclidean norms for each vector in the feature matrix."""
    return np.linalg.norm(features, axis=1)

def cosine_similarity_task(i, features, norms):
    """Calculate cosine similarity row for a given index i."""
    row_similarities = np.dot(features, features[i]) / (norms * norms[i] + 1e-9)
    row_similarities[i] = 1.0  # Self-similarity
    return i, row_similarities

def compute_cosine_matrix(features, num_workers):
    # Convert features to a NumPy array for efficient operations
    features = np.array(features, dtype=np.float32)
    num_products = features.shape[0]

    # Calculate norms for each product vector in a single operation
    norms = vector_norms(features)
    
    # Initialize the similarity matrix
    cosine_matrix = np.zeros((num_products, num_products), dtype=np.float32)

    # Use parallel processing to calculate cosine similarity rows
    with Pool(processes=num_workers) as pool:
        results = pool.starmap(cosine_similarity_task, [(i, features, norms) for i in range(num_products)])

    # Fill the similarity matrix with results
    for i, row_similarities in results:
        cosine_matrix[i, :] = row_similarities

    return cosine_matrix

def main(input_file):
    # Read data from input file
    with open(input_file, 'r') as f:
        n, m = map(int, f.readline().strip().split())
        features = [list(map(int, f.readline().strip().split())) for _ in range(n)]
    
    start = time()
    # Compute cosine similarity matrix
    cosine_matrix = compute_cosine_matrix(features, min(cpu_count(), 8))
    end = time()
    return cosine_matrix, end - start

if __name__ == "__main__":
    output, time_run = main("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/cosinesimulate/input.txt")
    for line in output:
        print(" ".join(f"{value:.4f}" for value in line))  # In kết quả ra màn hình console (nếu cần)
    print(time_run)
