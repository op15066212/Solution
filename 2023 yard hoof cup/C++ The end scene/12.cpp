#include <bits/stdc++.h>

using namespace std;
#define int long long

int n;
const vector<int> W = {1, 3, 7, 13};

void solve() {
    cin >> n;
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++) {
        int temp = INT_MAX;
        for (const auto&w: W) {
            if (i - w >= 0) {
                temp = min(temp, dp[i - w]);
            }
        }
        if (temp != INT_MAX) {
            dp[i] = temp + 1;
        }
    }
    cout << dp[n] << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
