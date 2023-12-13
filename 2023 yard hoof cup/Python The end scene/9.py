def check() -> bool:
    if len(A) <= 6:
        return False
    s1 = {}
    s2 = {}
    s3 = {}
    for c in A:
        if c >= 'a' and c <= 'z':
            s1[c] = None
        if c >= 'A' and c <= 'Z':
            s2[c] = None
        if c >= '0' and c <= '9':
            s3[c] = None
    if len(s1) == 0 or len(s2) == 0 or len(s3) == 0:
        return False
    for i in range(1, len(A)):
        if A[i - 1] >= '0' and A[i - 1] <= '9' and A[i] >= '0' and A[i] <= '9':
            return False
    return True


def solve():
    global A

    A = input()
    if check():
        print("True")
    else:
        print("False")


if __name__ == '__main__':
    solve()
