import heapq


class P:
    def __init__(self, index, val):
        self.index = index
        self.val = val

    def __lt__(self, other):
        if self.val != other.val:
            return self.val > other.val
        return self.index < other.index


def solve():
    N = int(input())
    temp = list(map(int, input().split()))
    arr = []
    for i in range(N):
        arr.append(P(i + 1, temp[i]))

    heapq.heapify(arr)

    n = int(input())
    result = []
    for _ in range(n):
        result.append(heapq.heappop(arr).index)

    print(' '.join(map(str, result)))


if __name__ == '__main__':
    solve()
