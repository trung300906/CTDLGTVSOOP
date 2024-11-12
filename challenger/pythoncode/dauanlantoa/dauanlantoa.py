import concurrent.futures
#import os

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

def process_pairs(pairs, index):
    result = []
    for key, value in pairs:
        longer, shorter = key, value

        if len(shorter) > len(longer):
            longer, shorter = shorter, longer

        count = kmp_search(longer, shorter)

        if count == 0:
            result.append("-1")
        else:
            result.append(str(count))

    return (index, result)

def MAIN(filename="/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/input.txt"):
    with open(filename, "r") as file:
        data = file.readlines()

    n = int(data[0].strip())
    pairs = []

    i = 1
    while i < len(data):
        key = data[i].strip()
        value = data[i + 1].strip()
        pairs.append((key, value))
        i += 2

    # Tự động phát hiện số lõi CPU
    num_processes = 8 #os.cpu_count()  # Lấy số lượng lõi CPU hiện có
    #print(f"Using {num_processes} processes.")  # In ra số tiến trình sử dụng

    # Chia cặp chuỗi thành các nhóm nhỏ cho từng tiến trình
    chunk_size = len(pairs) // num_processes + 1
    chunks = [pairs[i:i + chunk_size] for i in range(0, len(pairs), chunk_size)]

    result = [None] * len(pairs)
    with concurrent.futures.ProcessPoolExecutor(max_workers=num_processes) as executor:
        futures = [executor.submit(process_pairs, chunk, idx) for idx, chunk in enumerate(chunks)]
        for future in concurrent.futures.as_completed(futures):
            index, res = future.result()  # Lấy kết quả với chỉ số của tiến trình
            result[index * chunk_size : (index + 1) * chunk_size] = res  # Đảm bảo kết quả đúng thứ tự
    output = "\n".join(result)
    #print(output)
    return (output)

if __name__ == "__main__":
    output = MAIN("/run/media/trunglinux/linuxandwindows/code/CTDLGTVSOOP/challenger/pythoncode/input.txt")
    print(output)  # In kết quả ra màn hình console (nếu cần)