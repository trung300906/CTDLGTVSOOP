import concurrent.futures
import sys

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

    # The first element of the tuple is the nth Fibonacci number
    return fib_doubling(n)[0]

# Wrapper function to call fibonacci_fast_doubling for multiprocessing
def calculate_fibonacci(position):
    return position, fibonacci_fast_doubling(position)

# Main code to calculate Fibonacci numbers in parallel
if __name__ == "__main__":
    positions = [10, 12, 12]  # Large Fibonacci positions to calculate

    # Use ProcessPoolExecutor to parallelize the calculations
    with concurrent.futures.ProcessPoolExecutor() as executor:
        results = list(executor.map(calculate_fibonacci, positions))

    # Print the results
    for pos, fib_num in results:
        print(f"Fibonacci number at position {pos} is {fib_num}")
