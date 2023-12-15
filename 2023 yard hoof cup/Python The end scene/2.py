def find(it: str) -> int:
    k = 0
    i = 0
    j = 0
    n = len(it)
    while k < n and i < n and j < n:
        if i == j:
            j += 1
        if it[(i + k) % n] == it[(j + k) % n]:
            k += 1
            continue
        if it[(i + k) % n] > it[(j + k) % n]:
            i += k + 1
        else:
            j += k + 1
        k = 0
    return min(i, j)


def solve():
    A = input()
    B = input()
    if len(A) != len(B) or B not in 2 * A:
        print("No")
        return
    a = find(A)
    A = A[a:] + A[:a]
    print("Yes")
    print(A)


if __name__ == "__main__":
    solve()
