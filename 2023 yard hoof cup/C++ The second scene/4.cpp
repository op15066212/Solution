#include <bits/stdc++.h>

using namespace std;
#define int long long


void solve() {
    vector<int> da;
    int n;

    cin >> n;
    da.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> da[i];
    }
    int l = 0, r = n - 1;
    int sumL = 0, sumR = 0;
    while (l <= r) {
        if (sumL <= 2 * sumR) {
            sumL += da[l++];
        } else {
            sumR += da[r--];
        }
    }
    cout << l << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
