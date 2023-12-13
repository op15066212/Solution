#include <bits/stdc++.h>

using namespace std;
#define int long long


void solve() {
    int n;
    cin >> n;
    ostringstream oss;
    for (int i = 1; i <= n; i++) {
        if (i % 3 != 0) {
            string tmp(i, '*');
            oss << tmp << '\n';
        } else {
            oss << "|" << '\n';
        }
    }
    cout << oss.str();
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
