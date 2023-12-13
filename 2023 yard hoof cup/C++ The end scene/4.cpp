#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mod = 337077;
int p;
int q;
int k;
int T;
int res;
vector<vector<bool>> mark;
const vector<vector<int>> dirs = {
    {0, 0},
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

bool check(int x, int y) {
    for (const auto&dir: dirs) {
        int a = x + dir[0];
        int b = y + dir[1];
        if (a >= 0 && a < p && b >= 0 && b < q && mark[a][b]) {
            return false;
        }
    }
    return true;
}

void dfs(int pos, int man) {
    if (man == k) {
        res++;
        res %= mod;
        return;
    }
    for (int next = pos; next < p * q; next++) {
        int i = next / q;
        int j = next % q;
        if (check(i, j)) {
            mark[i][j] = true;
            dfs(next + 1, man + 1);
            mark[i][j] = false;
        }
    }
}

void solve() {
    cin >> T;
    ostringstream oss;
    for (int i = 0; i < T; i++) {
        cin >> p >> q >> k;
        if (k == 1) {
            oss << p * q << '\n';
        } else {
            mark.assign(p, vector<bool>(q, false));
            res = 0;
            dfs(0, 0);
            oss << res << '\n';
        }
    }
    cout << oss.str();
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
