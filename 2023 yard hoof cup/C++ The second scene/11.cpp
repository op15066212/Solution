#include <bits/stdc++.h>

using namespace std;
#define int long long

int a, m, n, k, t1, t2;
vector<pair<int,int>> da;

void init() {
    cin >> a >> m >> n >> k >> t1 >> t2;
    da.assign(a, {});
    for (int i = 0; i < a; i++) {
        cin >> da[i].first >> da[i].second;
    }
}

void solve() {
    init();
    int res = 0;
    for (const auto&[l, r]: da) {
        res += (r - l) * m;
    }
    for (int i = 1; i < da.size(); i += 1) {
        int len = da[i].first - da[i - 1].second;
        if (len < t1) {
            res += len * m;
        } else if (len < t1 + t2) {
            res += t1 * m + (len - t1) * n;
        } else {
            res += t1 * m + t2 * n + (len - t1 - t2) * k;
        }
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
