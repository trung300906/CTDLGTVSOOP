import numpy as np
import pyopencl as cl
import pyopencl.array
from numba import jit

# Example data
A = np.random.rand(1000, 512)
B = np.random.rand(512, 1000)

# Cosine similarity using numba for parallel processing on CPU
@jit(nopython=True, parallel=True)
def cosine_similarity(A, B):
    dot_product = np.dot(A, B)
    norm_A = np.linalg.norm(A, axis=1)
    norm_B = np.linalg.norm(B, axis=0)
    return dot_product / (norm_A[:, None] * norm_B)

# Cosine similarity using pyopencl for GPU
def cosine_similarity_opencl(A, B):
    ctx = cl.create_some_context()
    queue = cl.CommandQueue(ctx)

    A_buf = cl.Buffer(ctx, cl.mem_flags.READ_ONLY | cl.mem_flags.COPY_HOST_PTR, hostbuf=A)
    B_buf = cl.Buffer(ctx, cl.mem_flags.READ_ONLY | cl.mem_flags.COPY_HOST_PTR, hostbuf=B)
    C_buf = cl.Buffer(ctx, cl.mem_flags.WRITE_ONLY, A.nbytes)

    kernel_code = """
    __kernel void cosine_similarity(
        __global const float *A,
        __global const float *B,
        __global float *C,
        const int n, const int m, const int k) {
        int i = get_global_id(0);
        int j = get_global_id(1);
        float dot = 0.0;
        for (int x = 0; x < k; x++) {
            dot += A[i * k + x] * B[x * m + j];
        }
        float norm_A = 0.0, norm_B = 0.0;
        for (int x = 0; x < k; x++) {
            norm_A += A[i * k + x] * A[i * k + x];
            norm_B += B[x * m + j] * B[x * m + j];
        }
        C[i * m + j] = dot / (sqrt(norm_A) * sqrt(norm_B));
    }
    """

    program = cl.Program(ctx, kernel_code).build()
    program.cosine_similarity(queue, A.shape, None, A_buf, B_buf, C_buf, np.int32(A.shape[0]), np.int32(B.shape[1]), np.int32(A.shape[1]))

    C = np.empty_like(A)
    cl.enqueue_copy(queue, C, C_buf).wait()
    return C

# Calculate cosine similarity
cos_sim_numba = cosine_similarity(A, B)
cos_sim_opencl = cosine_similarity_opencl(A, B)
print("Cosine similarity (Numba):", cos_sim_numba)
print("Cosine similarity (OpenCL):", cos_sim_opencl)
