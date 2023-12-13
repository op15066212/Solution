def change(it: str) -> str:
    if it[0] >= '0' and it[0] <= '9':
        num = int(it)
        res = ""
        while num > 0:
            res += str(chr(num % 26 + ord('a')))
            num //= 26
        return res[::-1]
    else:
        num = 0
        bas = 1
        for i in range(len(it) - 1, -1, -1):
            num += bas * (ord(it[i]) - ord('a'))
            bas *= 26
        return str(num)


def next(i: int, A: str) -> int:
    p1 = i
    p2 = i
    while p1 < len(A) and A[p1] >= '0' and A[p1] <= '9':
        p1 += 1
    while p2 < len(A) and A[p2] >= 'a' and A[p2] <= 'z':
        p2 += 1
    return max(p1, p2)


def solve():
    global A

    A = input()
    i = 0
    res = ""
    while i < len(A):
        j = next(i, A)
        res += change(A[i:j])
        i = j
    print(res)


if __name__ == '__main__':
    solve()
