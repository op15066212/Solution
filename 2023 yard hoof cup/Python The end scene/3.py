def check() -> bool:
    for i in range(2, n):
        if arr[i - 2] < arr[i - 1] and arr[i - 1] < arr[i]:
            return True
    return False


def solve():
    global n, arr
    n = int(input())
    arr = list(map(int, input().split()))
    if check():
        print("True")
    else:
        print("False")


if __name__ == '__main__':
    solve()
