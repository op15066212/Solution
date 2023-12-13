#include <bits/stdc++.h>

using namespace std;
#define int long long

vector<int> a;

void solve() {
    int n;
    cin >> n;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        a[i] = i * (i + 1) / 2;
    }
    for (int i = 2; i <= n; i++) {
        a[i] += a[i - 1];
    }
    cout << a[n] << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
