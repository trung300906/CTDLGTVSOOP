import concurrent.futures
import sys

sys.set_int_max_str_digits(100000000)

# Function to calculate one Fibonacci step with large integers
def fibonacci_step(a, b, steps):
    for _ in range(steps):
        a, b = b, str(int(a) + int(b))
    return a, b

# Process each chunk independently to avoid pickling issues
def process_chunk(task):
    a, b, steps = task
    final_a, _ = fibonacci_step(a, b, steps)
    return final_a

# Function to find large Fibonacci number using process-based parallelism
def find_large_fibonacci_with_splitting(position, chunk_size=100000):
    # Split the position into chunks for parallel processing
    tasks = []
    a, b = "0", "1"
    remaining_steps = position

    # Generate tasks for each chunk
    while remaining_steps > 0:
        steps = min(chunk_size, remaining_steps)
        tasks.append((a, b, steps))
        a, b = fibonacci_step(a, b, steps)  # Update state for the next chunk
        remaining_steps -= steps

    # Use ProcessPoolExecutor for parallel processing
    with concurrent.futures.ProcessPoolExecutor() as executor:
        # Submit each task and collect the results
        results = list(executor.map(process_chunk, tasks))

    # The last result in the list will contain the final Fibonacci number at `position`
    return results[-1]

# Call the main function with Fibonacci positions to calculate
if __name__ == "__main__":
    positions = [10, 12, 1000000]  # Fibonacci positions to calculate
    for pos in positions:
        fib_num = find_large_fibonacci_with_splitting(pos)
        print(f"Fibonacci number at position {pos} is {fib_num}")
