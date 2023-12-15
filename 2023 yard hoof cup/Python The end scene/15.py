import math
from queue import PriorityQueue


def create_ST():
    for i in range(1, n + 1):
        F[i][0] = i
    k = int(math.log2(n))
    for i in range(1, k + 1):
        for j in range(1, n - (1 << i) + 2):
            x = F[j][i - 1]
            y = F[j + (1 << (i - 1))][i - 1]
            F[j][i] = x if Sum[x] > Sum[y] else y


def query_ST(l, r):
    k = int(math.log2(r - l + 1))
    x = F[l][k]
    y = F[r - (1 << k) + 1][k]
    return x if Sum[x] > Sum[y] else y


class Node:
    def __init__(self, start, l, r):
        self.start = start
        self.l = l
        self.r = r
        self.maxIndex = query_ST(l, r)

    def get(self, sum):
        return sum[self.maxIndex] - sum[self.start - 1]

    def __lt__(self, other):
        return self.get(Sum) > other.get(Sum)


def solve():
    global n, k, L, R, Sum, F
    n, k, L, R = map(int, input().split())
    Sum = [0] * (n + 1)
    F = [[0] * (int(math.log2(n)) + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        Sum[i] = int(input())
        Sum[i] += Sum[i - 1]
    create_ST()
    queue = PriorityQueue()
    for i in range(1, n + 1):
        if i + L - 1 <= n:
            queue.put(Node(i, i + L - 1, min(i + R - 1, n)))
    ans = 0
    for i in range(k):
        it = queue.get()
        ans += it.get(Sum)
        if it.maxIndex > it.l:
            queue.put(Node(it.start, it.l, it.maxIndex - 1))
        if it.maxIndex < it.r:
            queue.put(Node(it.start, it.maxIndex + 1, it.r))
    print(ans)


if __name__ == "__main__":
    solve()
