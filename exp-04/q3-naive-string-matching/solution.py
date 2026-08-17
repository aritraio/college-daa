text = input()
pattern = input()
n, m = len(text), len(pattern)

found = False
for i in range(n - m + 1):
    j = 0
    while j < m and text[i + j] == pattern[j]:
        j += 1
    if j == m:
        print(f"Pattern found at index {i}")
        found = True

if not found:
    print("not found")