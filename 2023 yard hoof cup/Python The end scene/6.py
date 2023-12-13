def solve():
    x, y, L = map(int, input().split())
    ans1 = 0
    ans2 = 0
    while True:
        if L < abs(L - x):
            break
        ans1 += abs(L - x)
        L -= abs(L - x)

        if L < abs(L - y):
            break
        ans2 += abs(L - y)
        L -= abs(L - y)
    print(str(ans1) + " " + str(ans2))


if __name__ == '__main__':
    solve()
