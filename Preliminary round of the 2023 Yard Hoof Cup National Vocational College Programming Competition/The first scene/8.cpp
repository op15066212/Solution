#include <bits/stdc++.h>

using namespace std;
#define int long long

int push(int i) {
    i *= 2;
    if (i % 10 == 0) {
        return 0;
    }
    return i;
}

void solve() {
    int n;
    cin >> n;
    int ans = push(n);
    cout << ans << '\n';
}


auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
