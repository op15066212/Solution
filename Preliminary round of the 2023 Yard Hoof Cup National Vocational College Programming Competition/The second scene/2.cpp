#include <bits/stdc++.h>

// 错
using namespace std;
#define int long long

vector<string> dat; //数据
int n, m; //行列大小
char c; //指定字符
unordered_set<char> myset; //结果集

const vector<vector<int>> dirs = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

void search(int i,int j) {
    if (dat[i][j] != c) {
        return;
    }
    for (const auto&dir: dirs) {
        int a = i + dir[0];
        int b = j + dir[1];
        if (a > -1 && a < n
            && b > -1 && b < m
            && dat[a][b] != c
            && dat[a][b] != '0') {
            myset.insert(dat[a][b]);
        }
    }
}

void solve() {
    cin >> n >> m >> c;
    dat.assign(n, "0");
    for (int i = 0; i < n; i++) {
        cin >> dat[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            search(i, j);
        }
    }
    cout << myset.size() << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
