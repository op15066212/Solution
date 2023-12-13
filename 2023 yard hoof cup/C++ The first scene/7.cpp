#include <bits/stdc++.h>

using namespace std;
#define int long long

vector<vector<int>> graph;
vector<bool> used;
int n;

bool dfs(int i) {
    if (used[i]) {
        return false;
    }
    if (i == n) {
        return true;
    }
    used[i] = true;
    for (const auto&j: graph[i]) {
        if (used[j]) {
            continue;
        }
        if (dfs(j)) {
            return true;
        }
    }
    return false;
}

bool bfs(int i) {
    queue<int> from;
    from.emplace(i);
    while (!from.empty()) {
        int head = from.front();
        from.pop();
        if (head == n) {
            return true;
        }
        for (const auto&j: graph[head]) {
            if (used[j]) {
                continue;
            }
            used[j] = true;
            from.emplace(j);
        }
    }
    return false;
}

void solve() {
    int m;
    cin >> n >> m;
    used.assign(n + 1, false);
    graph.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
    }
    if (bfs(1)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
