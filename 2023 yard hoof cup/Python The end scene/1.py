def solve():
    n, t = map(int, input().split())
    arr: list[int] = list(map(int, input().split()))
    day = 1
    for it in arr:
        diff = 1440 - it
        if diff >= 60:
            t -= diff
        if t <= 0:
            break
        day += 1

    print(day)


if __name__ == '__main__':
    solve()
