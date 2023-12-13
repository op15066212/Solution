#include <bits/stdc++.h>

using namespace std;
#define int long long

class Union {
public:
    vector<int> parent;
    vector<int> size;
    int n{};

    Union() = default;

    explicit Union(int p) {
        this->n = p;
        size.assign(n + 1, 1);
        parent.assign(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        parent[i] = find(parent[i]);
        return parent[i];
    }

    bool connect() {
        int temp = find(1);
        for (int i = 2; i <= n; i++) {
            if (find(i) != temp) {
                return false;
            }
        }
        return true;
    }

    void merge(int a, int b) {
        int i = find(a);
        int j = find(b);
        if (i == j) {
            return;
        }
        if (size[i] > size[j]) {
            parent[j] = i;
            size[i] += size[j];
        } else {
            parent[i] = j;
            size[j] += size[i];
        }
    }
};

void solveOne() {
    int n, m;
    cin >> n >> m;
    vector<int> end;
    end.assign(n + 1, 0);
    Union tool(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        tool.merge(a, b);
        end[b]++;
    }
    int cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        if (end[i] == 1) {
            cnt1++;
        }
    }
    if (cnt1 == n - 1 && tool.connect()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

void solve() {
    int T;
    cin >> T;
    for (int k = 0; k < T; k++) {
        solveOne();
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
