import random

def generate_test_data(num_products, num_features, output_file):
    with open(output_file, 'w') as f:
        f.write(f"{num_products} {num_features}\n")
        for _ in range(num_products):
            features = [random.randint(1, 100) for _ in range(num_features)]
            f.write(" ".join(map(str, features)) + "\n")

if __name__ == "__main__":
    # Số lượng sản phẩm (dòng)
    num_products = 1000 # Thay đổi giá trị này theo nhu cầu của bạn
    # Số lượng đặc trưng mỗi sản phẩm (cột)
    num_features = 1000# Thay đổi giá trị này theo nhu cầu của bạn
    # Tên file đầu ra
    output_file = "/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/cosinesimulate/input.txt"

    generate_test_data(num_products, num_features, output_file)
    print(f"Generated test data with {num_products} products and {num_features} features into {output_file}")
