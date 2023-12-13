def solve():
    n = int(input())
    W = [1, 3, 7, 13]

    dp = [0] * (n + 1)
    for i in range(1, n + 1):
        temp = float('inf')
        for w in W:
            if i - w >= 0:
                temp = min(temp, dp[i - w])
        if temp != float('inf'):
            dp[i] = temp + 1

    print(dp[n])


if __name__ == '__main__':
    solve()
