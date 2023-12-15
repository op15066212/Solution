def clear(n: int) -> int:
    temp = str(n)
    size = len(temp)
    if 2 * k >= size:
        return n
    temp = temp[::-1]
    ans = ""
    i = 0
    while i < 2 * k and i < size:
        ans += temp[i]
        i += 1
    return int(ans[::-1])


def solve():
    global k
    n, k = map(int, input().split(" "))
    n = clear(n)
    mul = n
    ans = 1
    for i in range(k):
        temp = n
        NotFound = True
        j = 1
        while j <= 10:
            temp *= mul
            temp = clear(temp)
            if str(temp)[-(i + 1)] == str(n)[-(i + 1)]:
                ans *= j
                NotFound = False
                break
            j += 1
        if NotFound:
            print(-1)
            return
        mul **= j
        mul = clear(mul)
    print(ans)


if __name__ == '__main__':
    solve()
