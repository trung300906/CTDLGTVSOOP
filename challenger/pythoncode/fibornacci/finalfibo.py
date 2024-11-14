import concurrent.futures
import sys

sys.set_int_max_str_digits(100000000)

# Memoization dictionary to store already computed Fibonacci numbers
memo = {}

def fibonacci(n, modul):
    if n in memo:
        return memo[n]
    k = n // 2
    if (n % 2 == 0):
        memo[n] = (fibonacci(k, modul) * fibonacci(k, modul) + fibonacci(k - 1, modul) * fibonacci(k - 1, modul)) % modul
    else:
        memo[n] = (fibonacci(k, modul) * fibonacci(k + 1, modul) + fibonacci(k - 1, modul) * fibonacci(k, modul)) % modul
    return memo[n]

# Chia công việc tính toán Fibonacci giữa các luồng
def parallel_fibonacci(n, positions, num_workers, modul):
    results = []
    with concurrent.futures.ProcessPoolExecutor(max_workers=num_workers) as executor:
        # mapping of external tasks to internal tasks
        size = n // num_workers
        if (size == 0):
            size = n
        # calculate concurrently
        fibs = executor.map(fibonacci, positions, [modul] * n, chunksize=size)
        # store results
        results = dict(zip(positions, fibs))
    return results

def MAIN(input_file = "/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/inputfibornacci.txt"):
    with open(input_file, "r") as file:
        data = file.readlines()
    first_line = data[0].strip().split()
    n = int(first_line[0])
    modul = int(first_line[1])
    positions = [int(line.strip()) for line in data[1:n+1]]
    num_workers = 8  # Cố gắng giữ số lượng worker hợp lý, tránh quá tải với quá nhiều process
    memo[0] = 1 % modul
    memo[1] = 1 % modul
    fib_result = parallel_fibonacci(n, positions, num_workers, modul)
    result = []
    for pos in positions:
        result.append(fib_result[pos])

    # return "\n".join(map(str, result))
    return result

if __name__ == "__main__":
    output = MAIN("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/inputfibornacci.txt")
    #print(output)