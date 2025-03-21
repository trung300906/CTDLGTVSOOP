import concurrent.futures
import sys

sys.set_int_max_str_digits(100000000)

# Cải tiến phương pháp Fast Doubling với toán tử bitwise
def fibonacci_fast_doubling_bitwise(n):
    def fib_doubling(k):
        if k == 0:
            return 0, 1
        else:
            a, b = fib_doubling(k >> 1)  # Dịch bit phải thay cho chia 2
            c = a * ((b << 1) - a)       # c = a * (2 * b - a)
            d = a * a + b * b            # d = a^2 + b^2
            if k & 1:                    # Kiểm tra nếu k là số lẻ
                return d, c + d
            else:
                return c, d
    return fib_doubling(n)

# Function to calculate part of Fibonacci sequence
def compute_partial_fib(n, start, end):
    # Tính toán Fibonacci từ `start` đến `end`
    fib_start, fib_next = fibonacci_fast_doubling_bitwise(start)
    fib_end, _ = fibonacci_fast_doubling_bitwise(end)
    return fib_end - fib_start

# Chia công việc tính toán Fibonacci giữa các luồng
def parallel_fibonacci(n, num_workers):
    segment_size = n // num_workers
    ranges = [(i * segment_size, (i + 1) * segment_size) for i in range(num_workers)]
    ranges[-1] = (ranges[-1][0], n)  # Đảm bảo đoạn cuối cùng bao gồm cả `n`

    # Sử dụng ProcessPoolExecutor để tính toán song song
    with concurrent.futures.ProcessPoolExecutor(max_workers=num_workers) as executor:
        futures = [executor.submit(compute_partial_fib, n, start, end) for start, end in ranges]
        results = [future.result() for future in concurrent.futures.as_completed(futures)]

    # Tổng hợp kết quả từ các luồng
    final_result = sum(results)
    return final_result

def MAIN(input_file = "/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/inputfibornacci.txt"):
    with open(input_file, "r") as file:
        data = file.readlines()
    first_line = data[0].strip().split()
    n = int(first_line[0])
    modul = int(first_line[1])
    positions = [int(line.strip()) for line in data[1:n+1]]
    num_workers = 8
    result = []
    for pos in positions:
        fib_result = parallel_fibonacci(pos, num_workers) % modul
        result.append(fib_result)

    return "\n".join(map(str, result))

if __name__ == "__main__":
    output = MAIN("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/inputfibornacci.txt")
    print(output)
