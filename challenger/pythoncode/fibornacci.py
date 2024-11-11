import concurrent.futures
import queue
import sys

sys.set_int_max_str_digits(100000000)
# Hàm tính toán một bước Fibonacci với chuỗi số lớn
def fibonacci_step(a, b, steps):
    for _ in range(steps):
        a, b = b, str(int(a) + int(b))
    return a, b

# Hàm chia nhỏ công việc tính Fibonacci lớn và sử dụng hàng đợi công việc
def find_large_fibonacci_with_splitting(position, chunk_size=100000):
    task_queue = queue.Queue()
    
    # Khởi tạo công việc đầu tiên với (a, b) = ("0", "1")
    a, b = "0", "1"
    remaining_steps = position

    # Chia công việc thành các phần nhỏ (mỗi phần `chunk_size` bước)
    while remaining_steps > 0:
        steps = min(chunk_size, remaining_steps)
        task_queue.put((a, b, steps))
        remaining_steps -= steps
        a, b = fibonacci_step(a, b, steps)  # Cập nhật trạng thái để chia phần tiếp theo

    # Kết quả cuối cùng
    result = None

    # Hàm xử lý từng công việc từ hàng đợi
    def worker():
        nonlocal result
        while not task_queue.empty():
            a, b, steps = task_queue.get()
            a, b = fibonacci_step(a, b, steps)
            result = a  # Cập nhật kết quả cuối cùng
            task_queue.task_done()

    # Sử dụng ThreadPoolExecutor với số luồng tối đa
    max_workers = 8  # Số luồng xử lý đồng thời
    with concurrent.futures.ThreadPoolExecutor(max_workers=max_workers) as executor:
        futures = [executor.submit(worker) for _ in range(max_workers)]
        concurrent.futures.wait(futures)  # Đợi tất cả công việc hoàn tất

    return result

# Gọi hàm chính với các vị trí Fibonacci cần tìm
if __name__ == "__main__":
    positions = [10, 12, 1000000]  # Các vị trí Fibonacci cần tính
    for pos in positions:
        fib_num = find_large_fibonacci_with_splitting(pos)
        print(f"Fibonacci number at position {pos} is {fib_num}")
