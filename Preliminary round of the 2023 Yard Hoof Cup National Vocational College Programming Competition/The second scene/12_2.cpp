#include <bits/stdc++.h>

using namespace std;
#define int long long

struct P {
    int key{}, val{}; //存储编号和大小

    P() = default;

    P(long long key, long long val)
        : key(key),
          val(val) {
    }
};

int a, b, n;
vector<vector<int>> maze;

void init() {
    cin >> a >> b >> n;
    maze.assign(a, vector<int>(b, 0));
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> maze[i][j];
        }
    }
}

class node {
public:
    int l{}, r{};
    int max = INT_MIN, min = INT_MAX;

    node() = default;

    node(int l, int r) : l(l), r(r) {
    }
};

class Segment {
public:
    vector<node> tree;
    vector<int> arr;

    explicit Segment(const vector<int>&a) {
        this->arr = a;
        int size = (int) arr.size();
        tree.assign(4 * size, {});
        build(1, size);
    }

    void build(int l, int r, int p = 1) {
        // NOLINT(*-no-recursion)
        node&it = tree[p];
        it = {l, r};
        if (l == r) {
            it.max = it.min = arr[l - 1];
            return;
        }
        int m = (l + r) / 2;
        build(l, m, getLeft(p));
        build(m + 1, r, getRight(p));
        pushUp(p);
    }

    pair<int,int> query(int l, int r, int p = 1) {
        // NOLINT(*-no-recursion)
        node&it = tree[p];
        if (it.l >= l && it.r <= r) {
            return {it.min, it.max};
        }
        pair<int,int> ans{INT_MAX,INT_MIN};
        int m = (it.l + it.r) / 2;
        if (l <= m) {
            pair<int, int> left = query(l, r, getLeft(p));
            ans.first = min(ans.first, left.first);
            ans.second = max(ans.second, left.second);
        }
        if (r > m) {
            pair<int, int> right = query(l, r, getRight(p));
            ans.first = min(ans.first, right.first);
            ans.second = max(ans.second, right.second);
        }
        return ans;
    }

    void pushUp(int p) {
        node&it = tree[p];
        node&Left = tree[getLeft(p)];
        node&Right = tree[getRight(p)];
        it.max = max(Left.max, Right.max);
        it.min = min(Left.min, Right.min);
    }

    static int getParent(int p) {
        return p / 2;
    }

    static int getLeft(int p) {
        return 2 * p;
    }

    static int getRight(int p) {
        return 2 * p + 1;
    }
};


pair<vector<int>, vector<int>> solveLine(const vector<int>&da) {
    int m = da.size();
    Segment tool(da);
    pair<vector<int>, vector<int>> ans;
    for (int i = 1; i <= m - n + 1; i++) {
        pair<int,int> it = tool.query(i, i + n - 1);
        ans.first.emplace_back(it.first);
        ans.second.emplace_back(it.second);
    }
    return ans;
}

vector<vector<int>> transpose(const vector<vector<int>>&bas) {
    vector<vector<int>> ans(bas[0].size(), vector<int>(bas.size()));
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            ans[i][j] = bas[j][i];
        }
    }
    return ans;
}

pair<vector<vector<int>>, vector<vector<int>>> search() {
    vector<vector<int>> Min1;
    vector<vector<int>> Max1;
    for (int i = 0; i < a; i++) {
        pair<vector<int>, vector<int>> temp = solveLine(maze[i]);
        Min1.emplace_back(temp.first);
        Max1.emplace_back(temp.second);
    }
    Min1 = transpose(Min1);
    Max1 = transpose(Max1);
    vector<vector<int>> Min2;
    vector<vector<int>> Max2;
    for (int i = 0; i < Min1.size(); i++) {
        pair<vector<int>, vector<int>> temp1 = solveLine(Min1[i]);
        pair<vector<int>, vector<int>> temp2 = solveLine(Max1[i]);
        Min2.emplace_back(temp1.first);
        Max2.emplace_back(temp2.second);
    }
    return {Min2, Max2};
}


void solve() {
    init();
    pair<vector<vector<int>>, vector<vector<int>>> bas = search();
    vector<vector<int>> Min = bas.first;
    vector<vector<int>> Max = bas.second;
    int ans = INT64_MAX;
    for (int i = 0; i < Min.size(); i++) {
        for (int j = 0; j < Min[0].size(); j++) {
            ans = min(ans, Max[i][j] - Min[i][j]);
        }
    }
    cout << ans << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
