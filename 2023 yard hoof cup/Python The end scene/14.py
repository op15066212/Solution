from collections import defaultdict
from typing import List


class TrieTree:
    def __init__(self):
        self.tree = defaultdict(lambda: [0 for _ in range(26)])
        self.cnt = 0
        self.end = defaultdict(int)
        self.sum = defaultdict(int)

    def insert(self, s, v):
        p = 0
        n = len(s)
        for i in range(n):
            it = ord(s[i]) - ord('a')
            if not self.tree[p][it]:
                self.cnt += 1
                self.tree[p][it] = self.cnt
            p = self.tree[p][it]
        self.end[p] += 1
        self.sum[p] += v

    def find(self, s) -> int:
        p = 0
        n = len(s)
        for i in range(n):
            it = ord(s[i]) - ord('a')
            if not self.tree[p][it]:
                return 0
            p = self.tree[p][it]
        return p

    def update_num(self, x, v):
        if x in self.end:
            self.sum[x] += v * self.end[x]
        for i in range(26):
            if not self.tree[x][i]:
                continue
            self.update_num(self.tree[x][i], v)

    def search_num(self, x) -> int:
        ans = 0
        if x in self.sum:
            ans += self.sum[x]
        for i in range(26):
            if not self.tree[x][i]:
                continue
            ans += self.search_num(self.tree[x][i])
        return ans

    def update(self, s, v):
        x = self.find(s)
        if x == 0:
            return
        self.update_num(x, v)

    def search(self, s) -> int:
        x = self.find(s)
        if x == 0:
            return 0
        return self.sum[x]

    def search_all(self, s) -> int:
        x = self.find(s)
        if x == 0:
            return 0
        return self.search_num(x)


def solve():
    n = int(input())
    tree = TrieTree()
    res = ""
    for i in range(n):
        line: List[str] = list(input().split(" "))
        op = int(line[0])
        if op == 1:
            s = line[1]
            v = int(line[2])
            tree.insert(s, v)
        elif op == 2:
            s = line[1]
            v = int(line[2])
            tree.update(s, v)
        elif op == 3:
            s = line[1]
            res += str(tree.search(s)) + '\n'
        elif op == 4:
            s = line[1]
            res += str(tree.search_all(s)) + '\n'
    print(res, end='')


if __name__ == '__main__':
    solve()
