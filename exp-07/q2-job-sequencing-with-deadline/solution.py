def main():
    n = int(input())
    jobs = []
    max_d = 0
    for _ in range(n):
        jid, deadline, profit = map(int, input().split())
        jobs.append((jid, deadline, profit))
        max_d = max(max_d, deadline)

    jobs.sort(key=lambda x: x[2], reverse=True)

    slot = [0] * max_d
    total = 0
    for jid, deadline, profit in jobs:
        for j in range(deadline - 1, -1, -1):
            if slot[j] == 0:
                slot[j] = jid
                total += profit
                break

    print("Selected jobs:", *[s for s in slot if s != 0])
    print("Total profit:", total)


main()