#include <bits/stdc++.h>

using namespace std;
#define int unsigned long long


const int P = 131;
vector<int> Q;

struct HashStr {
    vector<int> A;
    string bas;

    HashStr() = default;

    [[nodiscard]] int size() const {
        return bas.size();
    }

    explicit HashStr(const string&str) {
        bas = str;
        init();
    }

    void init() {
        A.assign(bas.size(), 0);
        A[0] = bas[0];
        for (int i = 1; i < A.size(); i++) {
            A[i] = A[i - 1] * P + bas[i];
        }
    }

    [[nodiscard]] int hashStr(int l, int r) const {
        int start = l > 0 ? A[l - 1] : 0;
        return A[r] - start * Q[r - l + 1];
    }
};


HashStr Bas, Key;
int p;

int diffrent(int l = 0, int r = Key.size() - 1) {
    if (l == r) {
        return Bas.bas[p + l] != Key.bas[l];
    }
    int res = 0;
    int mid = (l + r) / 2;
    if (Bas.hashStr(p + l, p + mid) != Key.hashStr(l, mid)) {
        res += diffrent(l, mid);
    }
    if (res > 3) {
        return res;
    }
    if (Bas.hashStr(p + mid + 1, p + r) != Key.hashStr(mid + 1, r)) {
        res += diffrent(mid + 1, r);
    }
    return res;
}

void initQ(int n) {
    Q.assign(n, 0);
    int bas = 1;
    for (unsigned long long&i: Q) {
        i = bas;
        bas *= P;
    }
}

void solveOne() {
    cin >> Bas.bas >> Key.bas;
    initQ(Key.size());
    Bas.init();
    Key.init();
    int res = 0;
    for (p = 0; p <= Bas.size() - Key.size(); p++) {
        res += (diffrent() <= 3);
    }
    cout << res << '\n';
}

void solve() {
    int T = 1;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solveOne();
    }
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
