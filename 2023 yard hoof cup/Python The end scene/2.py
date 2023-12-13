def find(it: str) -> int:
    k = 0
    i = 0
    j = 1
    n = len(it)
    while k < n and i < n and j < n:
        if it[(i + k) % n] == it[(j + k) % n]:
            k += 1
            continue
        if it[(i + k) % n] > it[(j + k) % n]:
            i += k + 1
        else:
            j += k + 1
        if i == j:
            i += 1
        k = 0
    return min(i, j)


def solve():
    A = input()
    B = input()
    a = find(A)
    b = find(B)
    A = A[a:] + A[:a]
    B = B[b:] + B[:b]
    if A == B:
        print("Yes")
        print(A)
    else:
        print("No")


if __name__ == "__main__":
    solve()
