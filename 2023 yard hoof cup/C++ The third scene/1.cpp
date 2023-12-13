#include <bits/stdc++.h>

using namespace std;
#define int long long

int solveDay(int n) {
    if (n % 8 == 0) {
        return 0;
    }
    return n * (n + 1) / 2;
}

void solve() {
    int a, b;
    cin >> a >> b;
    int res = 0;
    for (int i = a; i <= b; i++) {
        res += solveDay(i);
    }
    cout << res << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
