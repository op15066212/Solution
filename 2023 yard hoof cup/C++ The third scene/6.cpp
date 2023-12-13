#include <bits/stdc++.h>

using namespace std;
#define int long long

string tmp;

string dfs(int k) {
    if (k == 1) {
        return tmp;
    }
    string res;
    for (int i = 0; i < tmp.size(); i++) {
        if (i % k == 0) {
            res += tmp[i];
        }
    }
    return res;
}

void solve() {
    int k;
    cin >> k >> tmp;
    cout << dfs(k) << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
