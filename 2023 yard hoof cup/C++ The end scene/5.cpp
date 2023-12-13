#include <bits/stdc++.h>

using namespace std;
#define int long long

int n;
vector<int> tree;
int ms;
int res;

int getLeft(int i) {
    return 2 * i + 1;
}

int getRight(int i) {
    return 2 * i + 2;
}

void dfs(int i,int deep) {
    if (i >= n) {
        return;
    }
    ms = max(ms, tree[i] * deep);
    dfs(getLeft(i), deep + 1);
    dfs(getRight(i), deep + 1);
}

void dfs(int i) {
    ms = 0;
    dfs(i, 0);
    res += ms;
}

void solve() {
    cin >> n;
    tree.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }
    res = 0;
    for (int i = 0; i < n; i++) {
        dfs(i);
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
