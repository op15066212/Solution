#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int m, n;
    cin >> m >> n;
    int sum = 0;
    int cnt = 0;
    while (true) {
        sum += m;
        cnt++;
        if (sum % 10 == n || sum % 10 == 0) {
            break;
        }
    }
    cout << cnt << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
