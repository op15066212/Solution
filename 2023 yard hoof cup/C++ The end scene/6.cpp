#include <bits/stdc++.h>

using namespace std;
#define int long long

int x, y, L;

void solve() {
    cin >> x >> y >> L;
    int ans1 = 0, ans2 = 0;
    while (true) {
        if (L < abs(L - x)) {
            break;
        }
        ans1 += abs(L - x);
        L -= abs(L - x);

        if (L < abs(L - y)) {
            break;
        }
        ans2 += abs(L - y);
        L -= abs(L - y);
    }
    cout << ans1 << " " << ans2 << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
