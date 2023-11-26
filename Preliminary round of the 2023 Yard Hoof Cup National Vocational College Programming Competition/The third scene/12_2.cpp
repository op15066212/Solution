#include <bits/stdc++.h>

using namespace std;
#define int long long

void solveOne() {
    string bas, key;
    cin >> bas >> key;
    int res = 0;
    for (int i = 0; i < bas.size() - key.size() + 1; i++) {
        int diff = 0;
        for (int j = 0; j < key.size(); j++) {
            if (bas[i + j] != key[j]) {
                diff++;
            }
            if (diff > 3) {
                break;
            }
        }
        if (diff <= 3) {
            res++;
        }
    }
    cout << res << '\n';
}

void solve() {
    int T;
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
