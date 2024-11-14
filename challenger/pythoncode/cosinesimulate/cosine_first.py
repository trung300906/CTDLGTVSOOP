import numpy as np
from numpy.linalg import norm
import concurrent.futures
from time import time
def bitwise_dot_product(vec1, vec2):
    return sum(x * y for x, y in zip(vec1, vec2))

def bitwise_norm(vec):
    return sum(x * x for x in vec) ** 0.5

def cosine_similarity(vec1, vec2):
    dot_product = bitwise_dot_product(vec1, vec2)
    norm_vec1 = bitwise_norm(vec1)
    norm_vec2 = bitwise_norm(vec2)
    return dot_product / (norm_vec1 * norm_vec2)

def cosine_similarity_matrix(features):
    num_features = features.shape[1]
    similarity_matrix = np.zeros((num_features, num_features))
    
    # Sử dụng concurrent.futures để tính toán song song
    with concurrent.futures.ThreadPoolExecutor() as executor:
        future_to_index = {executor.submit(cosine_similarity, features[:, i], features[:, j]): (i, j)
                           for i in range(num_features) for j in range(num_features)}

        for future in concurrent.futures.as_completed(future_to_index):
            i, j = future_to_index[future]
            if i == j:
                similarity_matrix[i, j] = 1.0
            else:
                similarity_matrix[i, j] = round(future.result(), 4)
    
    return similarity_matrix

def MAIN(input_file):
    with open(input_file, "r") as file:
        data = file.readlines()
    
    first_line = data[0].strip().split()
    N = int(first_line[0])
    M = int(first_line[1])
    
    features = []
    for line in data[1:N + 1]:
        features.append([int(x) for x in line.strip().split()])
    start  = time()
    features = np.array(features)
    similarity_matrix = cosine_similarity_matrix(features)
    end  = time()
    return similarity_matrix, end - start

# Example usage
if __name__ == "__main__":
    similarity_matrix , time_run= MAIN("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/cosinesimulate/input.txt")
    #for row in similarity_matrix:
        #print(" ".join(f"{value:.4f}" for value in row))
    print(time_run, "seconds")
