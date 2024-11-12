import pyopencl as cl
import numpy as np

# OpenCL kernel code to calculate Fibonacci numbers
kernel_code = """
__kernel void fibonacci(__global int* fib, const unsigned int n) {
    int id = get_global_id(0);
    if (id == 0) {
        fib[id] = 0;
    } else if (id == 1) {
        fib[id] = 1;
    } else if (id < n) {
        fib[id] = fib[id - 1] + fib[id - 2];
    }
}
"""

# Function to calculate Fibonacci on GPU using OpenCL
def fibonacci_gpu(n):
    # Initialize OpenCL
    platforms = cl.get_platforms()
    device = platforms[0].get_devices()[0]  # Select first device
    context = cl.Context([device])
    queue = cl.CommandQueue(context)

    # Prepare memory buffers for Fibonacci numbers
    fib = np.zeros(n, dtype=np.int32)
    mf = cl.mem_flags
    fib_buffer = cl.Buffer(context, mf.READ_WRITE, fib.nbytes)

    # Create OpenCL program
    program = cl.Program(context, kernel_code).build()
    kernel = program.fibonacci
    kernel.set_arg(0, fib_buffer)
    kernel.set_arg(1, np.uint32(n))

    # Execute kernel with n work-items (each corresponding to a Fibonacci number)
    cl.enqueue_nd_range_kernel(queue, kernel, (n,), None)
    queue.finish()

    # Copy result back to host memory
    cl.enqueue_copy(queue, fib, fib_buffer).wait()

    return fib

# Example usage
if __name__ == "__main__":
    n = 10**8  # Fibonacci number position to calculate
    result = fibonacci_gpu(n)
    print(f"Fibonacci number at position {n} is {result[-1]}")
