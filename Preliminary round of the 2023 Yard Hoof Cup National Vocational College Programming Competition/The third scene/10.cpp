#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAX = 1e5 + 10;
vector<int> mark(MAX);
vector<int> Prime;

void prime() {
    for (int i = 2; i < MAX; i++) {
        for (int j = i; i * j < MAX; j++) {
            mark[i * j] = true;
        }
    }
    mark[0] = mark[1] = true;
}

void prime2() {
    for (int i = 2; i < MAX; i++) {
        Prime.push_back(i);
        for (const auto&it: Prime) {
            if (i * it >= MAX) {
                break;
            }
            mark[i * it] = true;
            if (i % it == 0) {
                break;
            }
        }
    }
    mark[0] = mark[1] = true;
}


int n, m;
vector<vector<int>> box;
int res;

void dfs(int x,int y) {
    if (y >= m) {
        y = 0;
        x++;
    }
    if (x >= n) {
        return;
    }
    int val = box[x][y];
    if (!mark[val]) {
        res++;
        dfs(x, y + val % 10);
    } else {
        dfs(x, y + 1);
    }
}

void solve() {
    cin >> n >> m;
    res = 0;
    box.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> box[i][j];
        }
    }
    dfs(0, 0);
    cout << res << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    prime2();
    solve();
    return 0;
}
