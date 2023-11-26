#include <bits/stdc++.h>

using namespace std;
#define int long long

const vector<vector<int>> dirs = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
};

struct node {
    pair<int,int> bas;
    int sum{};

    node() = default;

    node(int x, int y, int s) {
        bas.first = x;
        bas.second = y;
        sum = s;
    }

    node(const pair<long long, long long>&bas, long long sum)
        : bas(bas),
          sum(sum) {
    }

    friend bool operator==(const node&lhs, const node&rhs) {
        return lhs.bas == rhs.bas;
    }

    friend bool operator!=(const node&lhs, const node&rhs) {
        return !(lhs == rhs);
    }

    friend std::ostream& operator<<(std::ostream&os, const node&obj) {
        return os
               << "bas: " << obj.bas.first << " " << obj.bas.second << "\n"
               << " sum: " << obj.sum << "\n";
    }
};

int n, m;
vector<string> box;
node P, K, E;

// .道路
// #建筑
// P当前位置
// K另一支小队位置
// E制高点
int bfs(node from, node to, pair<int,int> other = {INT_MIN, INT_MAX}) {
    queue<node> que;
    vector<vector<int>> vis(n, vector<int>(m, false));
    que.emplace(from);
    while (!que.empty()) {
        node it = que.front();
        que.pop();
        if (it == to) {
            return it.sum;
        }
        for (const auto&dir: dirs) {
            int a = dir[0] + it.bas.first;
            int b = dir[1] + it.bas.second;
            if (a > -1 && a < n
                && b > -1 && b < m
                && box[a][b] != '#'
                && (a != other.first || b != other.second)
                && !vis[a][b]) {
                que.emplace(a, b, it.sum + 1);
                vis[a][b] = true;
            }
        }
    }
    return -1;
}

void solveOne() {
    cin >> n >> m;
    box.assign(n, "");
    for (int i = 0; i < n; i++) {
        cin >> box[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (box[i][j] == 'P') {
                P.bas.first = i;
                P.bas.second = j;
            }
            if (box[i][j] == 'K') {
                K.bas.first = i;
                K.bas.second = j;
            }
            if (box[i][j] == 'E') {
                E.bas.first = i;
                E.bas.second = j;
            }
        }
    }
    int a = bfs(P, K, E.bas);
    int b = bfs(K, E);
    // cout << a << " " << b << endl;
    if (a == -1 || b == -1) {
        cout << "No solution" << endl;
        return;
    }
    cout << a + b << endl;
}

void solve() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solveOne();
    }
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
