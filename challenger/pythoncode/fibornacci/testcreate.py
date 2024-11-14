import random

def generate_test_case(num_positions, max_position_value=100000):
    """
    Generates test cases for Fibonacci function.

    :param num_positions: Number of positions to generate
    :param max_position_value: Maximum value of any position
    :return: List of positions
    """
    positions = [random.randint(1, max_position_value) for _ in range(num_positions)]
    return positions

def save_test_case_to_file(file_path, num_positions, modulus, positions):
    """
    Saves the generated test case to a file.

    :param file_path: The path of the file to save the test case
    :param num_positions: Number of positions
    :param modulus: The modulus value
    :param positions: List of positions
    """
    with open(file_path, "w") as file:
        file.write(f"{num_positions} {modulus}\n")
        for pos in positions:
            file.write(f"{pos}\n")

def main():
    num_positions = 10**6
    max_modulus_value = 10**8 - 1
    file_path = "/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/inputfibornacci.txt"

    modulus = random.randint(1, max_modulus_value)
    positions = generate_test_case(num_positions)
    
    print("Generated modulus:", modulus)
    print("Generated positions:")
    for pos in positions:
        print(pos)

    save_test_case_to_file(file_path, num_positions, modulus, positions)
    print(f"Test case saved to '{file_path}'")

if __name__ == "__main__":
    main()
