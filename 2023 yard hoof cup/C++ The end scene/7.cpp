#include <bits/stdc++.h>

using namespace std;
#define int long long

int n;

void solve() {
    cin >> n;
    int ans = 0;
    for (int a = 1; a * a * a <= n; a++) {
        ans += 3 * (n / a / a - a) + 1;
        for (int b = a + 1; a * b * b <= n; b++, ans %= 3333) {
            ans += 6 * (n / a / b - b) + 3;
        }
    }
    cout << ans << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
