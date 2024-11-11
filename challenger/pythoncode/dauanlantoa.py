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

def MAIN(input_filename="input.txt"):
    with open(input_filename, "r") as file:
        data = file.readlines()
    
    n = int(data[0].strip())
    pairs = []

    for i in range(1, n + 1):
        key, value = data[i].strip().split()
        pairs.append((key, value))

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

    return " ".join(result)
