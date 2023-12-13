def solve():
    n, m = map(int, input().split())
    T = int(input())
    mark = [[False for _ in range(m)] for _ in range(n)]

    for i in range(n):
        line = list(map(int, input().split()))
        for j in range(m):
            if line[j] <= T:
                mark[i][j] = True

    R = float("inf")
    C = float("inf")

    def dfs():
        nonlocal R, C
        x1, y1, x2, y2 = n, m, -1, -1
        for i in range(n):
            for j in range(m):
                if mark[i][j]:
                    x1 = min(x1, i)
                    y1 = min(y1, j)
                    x2 = max(x2, i)
                    y2 = max(y2, j)
        R = min(R, x2 - x1 + 1)
        C = min(C, y2 - y1 + 1)

    dfs()
    print(R)
    print(C)


if __name__ == '__main__':
    solve()
