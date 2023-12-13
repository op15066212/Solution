#include <bits/stdc++.h>

using namespace std;
#define int long long

vector<int> dat;

void solve() {
    int n;
    cin >> n;
    dat.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> dat[i];
    }
    sort(dat.begin(), dat.end());
    cout << dat.back() - dat.front() << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
