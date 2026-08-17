pattern = input()
m = len(pattern)
lps = [0] * m
length, i = 0, 1
while i < m:
    if pattern[i] == pattern[length]:
        length += 1
        lps[i] = length
        i += 1
    elif length != 0:
        length = lps[length - 1]
    else:
        lps[i] = 0
        i += 1

print("LPS:" + "".join(f" {x}" for x in lps))
