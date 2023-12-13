#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, m, T;
vector<vector<bool>> mark;
int R, C;

void dfs() {
    int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mark[i][j]) {
                x1 = min(x1, i);
                y1 = min(y1, j);
                x2 = max(x2, i);
                y2 = max(y2, j);
            }
        }
    }
    R = min(R, x2 - x1 + 1);
    C = min(C, y2 - y1 + 1);
}

void solve() {
    cin >> n >> m >> T;
    mark.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            if (tmp <= T) {
                mark[i][j] = true;
            }
        }
    }
    R = INT_MAX;
    C = INT_MAX;
    dfs();
    cout << R << "\n" << C << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
