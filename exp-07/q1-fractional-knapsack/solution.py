def main():
    n, w = map(int, input().split())
    items = []
    for _ in range(n):
        weight, profit = map(int, input().split())
        items.append((weight, profit))

    items.sort(key=lambda x: x[1] / x[0], reverse=True)

    total = 0.0
    for weight, profit in items:
        if weight <= w:
            total += profit
            w -= weight
        else:
            total += profit * (w / weight)
            w = 0

    print(f"{total:.2f}")


main()