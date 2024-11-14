# import required libraries
import numpy as np
from numpy.linalg import norm

# define two lists or array
A = np.array([[3,4,1],[2,4,5], [4,4,2]])
B = np.array([4,5,6])
print("A:\n", A)
print("B:\n", B)

# compute cosine similarity
cosine = np.dot(A,B)/(norm(A, axis=1)*norm(B))
print("Cosine Similarity:\n", cosine)
