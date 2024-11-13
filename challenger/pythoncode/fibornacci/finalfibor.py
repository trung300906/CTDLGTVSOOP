import multiprocessing

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

# Hàm tính chu kỳ Pisano cho một modul cụ thể
def get_pisano_period(modul):
    a, b = 0, 1
    for i in range(0, modul * modul):
        a, b = b, (a + b) % modul
        if a == 0 and b == 1:
            return i + 1
    return None

# Hàm chính để xử lý song song các vị trí
def parallel_fibonacci_positions(positions, modul):
    num_workers = multiprocessing.cpu_count()
    chunk_size = max(1, len(positions) // num_workers)  # Đảm bảo chunk_size không bao giờ bằng 0
    chunks = [positions[i:i + chunk_size] for i in range(0, len(positions), chunk_size)]
    
    pisano_period = get_pisano_period(modul)  # Tính chu kỳ Pisano một lần duy nhất

    with multiprocessing.Pool(processes=num_workers) as pool:
        results = pool.starmap(find_fibonacci_position, [(chunk, modul, pisano_period) for chunk in chunks])

    # Gộp kết quả và sắp xếp lại theo thứ tự ban đầu
    results = [item for sublist in results for item in sublist]  # Flatten the list
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
    output , modul = MAIN("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/inputfibornacci.txt")
    #for pos, result in output:
        #print(f"{pos} % {modul} = {result}")