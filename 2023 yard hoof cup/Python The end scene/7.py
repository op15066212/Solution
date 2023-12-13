import math


def solve():
    n = int(input())
    ans = 0
    # ans += 6 * (n / a / b - b) 是 a != b && b != c, 也就是 a * b * c <= n, a > b > c。
    # ans += 3 * (n / a / a - a) 是两大一小，也是就是 a * a * b <= n，a > b。
    # ans += 3 * (sqrt(n / a) - a) 是两小一大，也就是 a * b * b <= n, a > b。
    # ans += 1 是 a == b && b == c。
    #
    # a * b * c <= n 变化一下就是 c <= n / a / b
    # a * a * b <= n 变化一下就是 b <= n / a / a
    # a * b * b <= n 变化一下就是 b <= sqrt(n / a)
    a = 1
    while a * a * a <= n:
        ans += 3 * (n // (a * a) - a)
        ans += 3 * (int(math.sqrt(n // a)) - a)
        ans += 1
        ans %= 3333

        b = a + 1
        while a * b * b <= n:
            if a * b * b <= n:
                ans += 6 * (n // (a * b) - b)
            ans %= 3333
            b += 1

        a += 1

    print(ans)


if __name__ == "__main__":
    solve()
