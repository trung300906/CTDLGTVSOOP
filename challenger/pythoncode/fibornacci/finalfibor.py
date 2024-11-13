import multiprocessing
from concurrent.futures import ProcessPoolExecutor, ThreadPoolExecutor

# Hàm tính số Fibonacci sử dụng phương pháp fast doubling với chu kỳ Pisano
def fibonacci_fast_doubling_bitwise(n, modul):
    def fib_doubling(k):
        if k == 0:
            return 0, 1
        else:
            a, b = fib_doubling(k >> 1)  # Dịch bit phải thay cho chia 2
            c = a * ((b << 1) - a) % modul     # c = a * (2 * b - a) % modul
            d = (a * a + b * b) % modul         # d = a^2 + b^2 % modul
            if k & 1:                           # Kiểm tra nếu k là số lẻ
                return d, (c + d) % modul
            else:
                return c, d
    return fib_doubling(n)[0]

# Hàm để tìm các số Fibonacci tại các vị trí cụ thể
def find_fibonacci_position(positions, modul, pisano_period):
    results = []
    for pos in positions:
        pos_mod_pisano = pos % pisano_period
        results.append((pos, fibonacci_fast_doubling_bitwise(pos_mod_pisano, modul)))
    return results

# Sử dụng bộ nhớ đệm để tránh tính lại chu kỳ Pisano cho cùng một modul
def get_pisano_period(modul):
    a, b = 0, 1
    for i in range(0, modul * modul):
        a, b = b, (a + b) % modul
        if a == 0 and b == 1:
            return i + 1
    return None

# Hàm chính để xử lý song song các vị trí sử dụng ProcessPoolExecutor
def parallel_fibonacci_positions(positions, modul):
    pisano_period = get_pisano_period(modul)  # Tính chu kỳ Pisano một lần duy nhất
    num_workers = multiprocessing.cpu_count() # Tăng gấp đôi số luồng xử lý
    # Tạo các chunk động để phân phối công việc tốt hơn
    chunk_size = max(num_workers, len(positions) // (num_workers * 100))  # Chia nhỏ các chunk hơn nữa
    chunks = [positions[i:i + chunk_size] for i in range(0, len(positions), chunk_size)]
    results = []

    with ProcessPoolExecutor(max_workers=num_workers) as process_executor:
        futures = [process_executor.submit(find_fibonacci_position, chunk, modul, pisano_period) for chunk in chunks]
        for future in futures:
            results.extend(future.result())
            
    # Sắp xếp lại kết quả theo thứ tự ban đầu
    results.sort(key=lambda x: positions.index(x[0]))
    return results

def MAIN(inputfile = "/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/inputfibornacci.txt"):
    with open(inputfile, "r") as file:
        data = file.readlines()
    first_line = data[0].strip().split()
    n = int(first_line[0])
    modul = int(first_line[1])
    positions = [int(line.strip()) for line in data[1:n+1]]
    results = parallel_fibonacci_positions(positions, modul)
    return results, modul

if __name__ == "__main__":
    output, modul = MAIN("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/inputfibornacci.txt")
    for pos, result in output:
        print(result)
