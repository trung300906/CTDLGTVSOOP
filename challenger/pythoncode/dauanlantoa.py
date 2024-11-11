def compute_lps(pattern):
    m = len(pattern)
    lps = [0] * m
    length = 0
    i = 1

    while i < m:
        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
    return lps

def kmp_search(text, pattern):
    n = len(text)
    m = len(pattern)
    lps = compute_lps(pattern)

    i = 0  # index for text
    j = 0  # index for pattern
    count = 0

    while i < n:
        if pattern[j] == text[i]:
            i += 1
            j += 1

        if j == m:
            count += 1  # found a match
            j = lps[j - 1]
        elif i < n and pattern[j] != text[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
    return count

def MAIN(input_filename="/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/input.txt"):
    with open(input_filename, "r") as file:
        data = file.readlines()

    n = int(data[0].strip())
    pairs = []

    i = 1
    while i < len(data):
        key = data[i].strip()
        value = data[i + 1].strip()
        pairs.append((key, value))
        i += 2

    result = []

    for key, value in pairs:
        longer, shorter = key, value

        # Giữ nguyên khoảng trắng giữa các từ
        # Không loại bỏ khoảng trắng

        if len(shorter) > len(longer):
            longer, shorter = shorter, longer

        count = kmp_search(longer, shorter)

        if count == 0:
            result.append("-1")
        else:
            result.append(str(count))

    return "\n".join(result)

# Example call to the MAIN function
if __name__ == "__main__":
    output = MAIN("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/input.txt")
    print(output)  # In kết quả ra màn hình console (nếu cần)
