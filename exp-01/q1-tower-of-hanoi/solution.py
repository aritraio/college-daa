def tower_of_hanoi(n, from_rod, to_rod, aux_rod, moves):
    if n == 1:
        print(f"Move disk 1 from {from_rod} to {to_rod}")
        moves[0] += 1
        return
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod, moves)
    print(f"Move disk {n} from {from_rod} to {to_rod}")
    moves[0] += 1
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod, moves)


n = int(input())
moves = [0]
tower_of_hanoi(n, 'A', 'C', 'B', moves)
print(f"Total moves: {moves[0]}")