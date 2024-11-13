#import numpy as np
import multiprocessing
from concurrent.futures import ProcessPoolExecutor, as_completed
#from functools import lru_cache
#from queue import Queue

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
def find_fibonacci_position(my_queue, other_queues, result_list, modul, pisano_period):
    while not my_queue.empty() or any(q.qsize() > 0 for q in other_queues):
        try:
            pos = my_queue.get_nowait()
        except:
            pos = None
            for q in other_queues:
                try:
                    pos = q.get_nowait()
                    break
                except:
                    continue
        
        if pos is None:
            break

        pos_mod_pisano = pos % pisano_period
        result = (pos, fibonacci_fast_doubling_bitwise(pos_mod_pisano, modul))
        result_list.append(result)

# Hàm để tính chu kỳ Pisano
def get_pisano_period(modul):
    a, b = 0, 1
    for i in range(0, modul * modul):
        a, b = b, (a + b) % modul
        if a == 0 and b == 1:
            return i + 1
    return None

# Hàm chính để xử lý song song các vị trí sử dụng ProcessPoolExecutor
def parallel_fibonacci_positions(positions, modul):
    pisano_period = get_pisano_period(modul)
    num_workers = multiprocessing.cpu_count()
    
    manager = multiprocessing.Manager()
    queues = [manager.Queue() for _ in range(num_workers)]
    result_list = manager.list()

    # Phân phối công việc vào các hàng đợi
    chunk_size = max(num_workers, len(positions) // (num_workers * 100)) 
    for i in range(num_workers):
        for pos in positions[i * chunk_size : (i + 1) * chunk_size]:
            queues[i].put(pos)
    
    with ProcessPoolExecutor(max_workers=num_workers) as executor:
        futures = [executor.submit(find_fibonacci_position, queues[i], queues[:i] + queues[i+1:], result_list, modul, pisano_period) for i in range(num_workers)]
        
        # Thu thập kết quả ngay khi mỗi worker hoàn thành
        for future in as_completed(futures):
            future.result()

    results = list(result_list)
    results.sort(key=lambda x: positions.index(x[0]))
    return results

def MAIN(inputfile="/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/inputfibornacci.txt"):
    with open(inputfile, "r") as file:
        data = file.readlines()
    first_line = data[0].strip().split()
    n = int(first_line[0])
    modul = int(first_line[1])
    positions = [int(line.strip()) for line in data[1:n + 1]]
    results = parallel_fibonacci_positions(positions, modul)
    return results, modul

if __name__ == "__main__":
    output, modul = MAIN("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/inputfibornacci.txt")
    for pos, result in output:
        print(f"F({pos}) % {modul} = {result}")
