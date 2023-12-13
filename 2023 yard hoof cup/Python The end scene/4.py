mod = 337077
dirs = [(0, 0), (1, 0), (-1, 0), (0, -1), (0, 1)]


def check(i: int, j: int) -> bool:
    for dir in dirs:
        a = i + dir[0]
        b = j + dir[1]
        if a >= 0 and a < p and b >= 0 and b < q and mark[a][b]:
            return False
    return True


def dfs(pos: int, man: int) -> int:
    if man == k:
        return 1
    res = 0
    for next in range(pos, p * q):
        i = next // q
        j = next % q
        if check(i, j):
            mark[i][j] = True
            res += dfs(next + 1, man + 1)
            res %= mod
            mark[i][j] = False
    return res


def solve():
    global p, q, T, k, mark
    T = int(input())
    ans = ""
    for i in range(T):
        p, q, k = map(int, input().split())
        if k == 1:
            ans += str(p * q) + '\n'
        else:
            mark = [[False for _ in range(q)] for _ in range(p)]
            ans += str(dfs(0, 0)) + '\n'
    print(ans, end='')


if __name__ == '__main__':
    solve()
