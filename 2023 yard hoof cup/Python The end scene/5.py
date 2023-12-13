def getLeft(i: int) -> int:
    return i * 2 + 1


def getRight(i: int) -> int:
    return i * 2 + 2


def dfs(i: int, deep: int):
    global ms
    if i >= n:
        return
    ms = max(ms, tree[i] * deep)
    dfs(getLeft(i), deep + 1)
    dfs(getRight(i), deep + 1)


def find(i: int):
    global res, ms
    ms = 0
    dfs(i, 0)
    res += ms


def solve():
    global n, tree, ms, res

    ms = 0
    res = 0
    n = int(input())
    tree = list(map(int, input().split()))
    for i in range(n):
        find(i)
    print(res)


if __name__ == '__main__':
    solve()
