import concurrent.futures
import sys

sys.set_int_max_str_digits(100000000)

# Fast doubling method to compute part of Fibonacci sequence
def fibonacci_fast_doubling(n):
    def fib_doubling(k):
        if k == 0:
            return "0", "1"
        else:
            a, b = fib_doubling(k // 2)
            c = str(int(a) * (2 * int(b) - int(a)))
            d = str(int(a) * int(a) + int(b) * int(b))
            if k % 2 == 0:
                return c, d
            else:
                return d, str(int(c) + int(d))
    return fib_doubling(n)

# Function to calculate part of Fibonacci sequence
def compute_partial_fib(n, start, end):
    # Compute Fibonacci for range from start to end
    fib_start, fib_next = fibonacci_fast_doubling(start)
    fib_end, _ = fibonacci_fast_doubling(end)
    return int(fib_end) - int(fib_start)

# Function to parallelize Fibonacci computation
def parallel_fibonacci(n, num_workers):
    # Divide the task into equal segments
    segment_size = n // num_workers
    ranges = [(i * segment_size, (i + 1) * segment_size) for i in range(num_workers)]
    ranges[-1] = (ranges[-1][0], n)  # Ensure last segment goes up to n

    # Use ProcessPoolExecutor to calculate Fibonacci in parallel
    with concurrent.futures.ProcessPoolExecutor(max_workers=num_workers) as executor:
        futures = [executor.submit(compute_partial_fib, n, start, end) for start, end in ranges]
        results = [future.result() for future in concurrent.futures.as_completed(futures)]

    # Combine results from all workers to get the final Fibonacci number
    final_result = sum(results)
    return final_result

if __name__ == "__main__":
    position = 10**8  # Large Fibonacci position to calculate
    num_workers = 8  # Using 8 cores
    print(f"Calculating Fibonacci number at position {position} using {num_workers} cores...")
    fib_result = parallel_fibonacci(position, num_workers)
    print(f"Fibonacci number at position {position} is {fib_result}")
