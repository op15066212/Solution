#include <bits/stdc++.h>

using namespace std;
#define int long long

struct MyTree {
    unordered_map<int, int[26]> tree;
    int cnt{};
    unordered_map<int, int> end;
    unordered_map<int, int> sum;

    void insert(const string&s, int v) {
        int p = 0;
        int n = (int) s.size();
        for (int i = 0; i < n; i++) {
            int it = s[i] - 'a';
            if (!tree[p][it]) {
                tree[p][it] = ++cnt;
            }
            p = tree[p][it];
        }
        end[p]++;
        sum[p] += v;
    }

    int find(const string&s) {
        int p = 0;
        int n = (int) s.size();
        for (int i = 0; i < n; i++) {
            int it = s[i] - 'a';
            if (!tree[p][it]) {
                return 0;
            }
            p = tree[p][it];
        }
        return p;
    }

    void update(int x, int v) {
        if (end.find(x) != end.end()) {
            sum[x] += v * end[x];
        }
        for (int i = 0; i < 26; i++) {
            if (!tree[x][i]) {
                continue;
            }
            update(tree[x][i], v);
        }
    }

    int search(int x) {
        int ans = 0;
        if (sum.find(x) != sum.end()) {
            ans += sum[x];
        }
        for (int i = 0; i < 26; i++) {
            if (!tree[x][i]) {
                continue;
            }
            ans += search(tree[x][i]);
        }
        return ans;
    }

    void update(const string&s, int v) {
        int x = find(s);
        if (x == 0) {
            return;
        }
        update(x, v);
    }

    int search(const string&s) {
        int x = find(s);
        if (x == 0) {
            return 0;
        }
        return sum[x];
    }

    int searchAll(const string&s) {
        int x = find(s);
        if (x == 0) {
            return 0;
        }
        return search(x);
    }
};

void solve() {
    int n;
    cin >> n;
    MyTree tree;
    ostringstream oss;
    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        string s;
        int v;
        if (op == 1) {
            cin >> s >> v;
            tree.insert(s, v);
        } else if (op == 2) {
            cin >> s >> v;
            tree.update(s, v);
        } else if (op == 3) {
            cin >> s;
            oss << tree.search(s) << '\n';
        } else if (op == 4) {
            cin >> s;
            oss << tree.searchAll(s) << '\n';
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
