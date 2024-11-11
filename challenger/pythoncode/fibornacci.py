import concurrent.futures
import sys
import os

sys.set_int_max_str_digits(100000000)

# Fast doubling Fibonacci method
def fibonacci_fast_doubling(n):
    if n == 0:
        return "0"
    elif n == 1:
        return "1"

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

    return fib_doubling(n)[0]

# Tính một phần của Fibonacci
def compute_partial_fib(pos):
    return pos, fibonacci_fast_doubling(pos)

# Parallel computation for large Fibonacci numbers
def parallel_fibonacci(position, num_workers):
    # Divide the position into smaller tasks for each worker
    segment_size = position // num_workers
    positions = [segment_size * i for i in range(num_workers)]
    positions.append(position)  # Add the final position for exact calculation

    # Use ProcessPoolExecutor to parallelize computation
    with concurrent.futures.ProcessPoolExecutor(max_workers=num_workers) as executor:
        futures = [executor.submit(compute_partial_fib, pos) for pos in positions]
        results = [future.result() for future in concurrent.futures.as_completed(futures)]

    # Combine the partial results (results are tuples with (position, fib_number))
    fib_values = sorted(results, key=lambda x: x[0])
    final_fib_value = fib_values[-1][1]  # The last position holds the Fibonacci for 'position'
    return final_fib_value

if __name__ == "__main__":
    position = 10**8  # Very large Fibonacci position
    num_workers = os.cpu_count()  # Automatically use all available cores
    print(f"Calculating Fibonacci number at position {position} using {num_workers} cores...")
    fib_result = parallel_fibonacci(position, num_workers)
    print(f"Fibonacci number at position {position} is {fib_result}")
