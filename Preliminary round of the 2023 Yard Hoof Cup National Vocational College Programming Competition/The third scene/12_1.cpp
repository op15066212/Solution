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

    [[nodiscard]] int hashStr(int l, int len) const {
        int start = l > 0 ? A[l - 1] : 0;
        return A[l + len - 1] - start * Q[len];
    }
};


HashStr Bas, Key;

int find(int x, int y) {
    int l = 0;
    int r = Key.size() - y - 1;
    while (r > l) {
        int mid = (l + r + 1) / 2;
        // if (bas.substr(x, mid) == key.substr(y, mid)) {
        if (Bas.hashStr(x, mid) == Key.hashStr(y, mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

bool check(int x) {
    int p1 = x;
    int p2 = 0;
    for (int i = 0; i < 3; i++) {
        int len = find(p1, p2) + 1;
        p1 += len, p2 += len;
        if (p1 >= Bas.size() || p2 >= Key.size()) {
            return true;
        }
    }
    int len = Key.size() - p2;
    return Bas.hashStr(p1, len) == Key.hashStr(p2, len);
    // return bas.substr(p1, len) == key.substr(p2, len);
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
    for (int i = 0; i <= Bas.size() - Key.size(); i++) {
        if (check(i)) {
            res++;
        }
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
