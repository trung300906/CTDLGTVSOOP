import random
import string

def random_string(length):
    """Hàm tạo chuỗi ngẫu nhiên gồm các ký tự chữ cái in hoa và in thường"""
    return ''.join(random.choices(string.ascii_letters + string.digits, k=length))

def generate_test_data(num_tests, max_length=100):
    """Hàm tạo dữ liệu test ngẫu nhiên với cả trường hợp có và không có -1"""
    data = []
    for _ in range(num_tests):
        # Tạo chuỗi dài ngẫu nhiên (key)
        longer_str_length = random.randint(10, max_length)  # Chiều dài chuỗi dài (tối thiểu 10 ký tự để chuỗi con có thể xuất hiện)
        longer_str = random_string(longer_str_length)
        
        # Xác định có hay không có -1 (có hoặc không có chuỗi con)
        has_match = random.choice([True, False])
        
        if has_match:
            # Tạo chuỗi con (shorter), đảm bảo chuỗi con là một phần của chuỗi dài
            shorter_str_length = random.randint(1, longer_str_length)  # Chiều dài chuỗi con không quá chiều dài của chuỗi dài
            start_index = random.randint(0, longer_str_length - shorter_str_length)  # Chọn vị trí bắt đầu của chuỗi con trong chuỗi dài
            shorter_str = longer_str[start_index:start_index + shorter_str_length]  # Đảm bảo chuỗi con là một phần của chuỗi dài
        else:
            # Tạo chuỗi con hoàn toàn khác với chuỗi dài
            shorter_str_length = random.randint(1, max_length)  # Chiều dài chuỗi con (không quá max_length)
            shorter_str = random_string(shorter_str_length)  # Chuỗi con không phải là phần của chuỗi dài
        
        # Thêm cặp vào dữ liệu
        data.append(f"{longer_str}\n{shorter_str}")
    return data

def save_test_data(filename, data):
    """Lưu dữ liệu vào tệp"""
    with open(filename, "w") as f:
        f.write(f"{len(data)}\n")  # Ghi số lượng cặp
        for pair in data:
            f.write(pair + "\n")  # Ghi mỗi cặp chuỗi

# Đường dẫn đến tệp bạn muốn lưu
filename = "/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/input.txt"

# Sinh 100 bộ test dữ liệu ngẫu nhiên
test_data = generate_test_data(100000)

# Lưu dữ liệu vào tệp
save_test_data(filename, test_data)

print(f"Đã tạo {len(test_data)} bộ test và lưu vào {filename}")
