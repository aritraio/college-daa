def compute_lps(p):
    m = len(p)
    lps = [0] * m
    length, i = 0, 1
    while i < m:
        if p[i] == p[length]:
            length += 1
            lps[i] = length
            i += 1
        elif length != 0:
            length = lps[length - 1]
        else:
            lps[i] = 0
            i += 1
    return lps


text = input()
pattern = input()
n, m = len(text), len(pattern)
lps = compute_lps(pattern)

i = j = 0
found = False
while i < n:
    if pattern[j] == text[i]:
        i += 1
        j += 1
    if j == m:
        print(f"Pattern found at index {i - j}")
        found = True
        j = lps[j - 1]
    elif i < n and pattern[j] != text[i]:
        if j != 0:
            j = lps[j - 1]
        else:
            i += 1

if not found:
    print("not found")
