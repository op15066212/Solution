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

vector<P> chage(const vector<int>&m) {
    vector<P> line;
    for (int i = 0; i < m.size(); i++) {
        line.emplace_back(i, m[i]);
    }
    return line;
}

pair<vector<int>, vector<int>> solveLine(const vector<P>&da) {
    deque<P> que1;
    deque<P> que2;
    pair<vector<int>, vector<int>> ans;
    int k = n;
    for (int i = 0; i < da.size(); i++) {
        int temp = da[i].val;
        // 后
        while (!que1.empty() && temp <= que1.back().val) {
            que1.pop_back(); //单调队列的操作，以保证单调
        }
        while (!que2.empty() && temp >= que2.back().val) {
            que2.pop_back();
        }
        // 后
        que1.push_back(da[i]); //压入队列
        que2.push_back(da[i]); //同上
        // 前
        while (i - k >= que1.front().key) {
            //T掉不在范围内的
            que1.pop_front();
        }
        while (i - k >= que2.front().key) {
            que2.pop_front(); //同上
        }
        if (i + 1 >= k) {
            // 前
            ans.first.emplace_back(que1.front().val);
            ans.second.emplace_back(que2.front().val);
        } //存答案
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
        pair<vector<int>, vector<int>> temp = solveLine(chage(maze[i]));
        Min1.emplace_back(temp.first);
        Max1.emplace_back(temp.second);
    }
    Min1 = transpose(Min1);
    Max1 = transpose(Max1);
    vector<vector<int>> Min2;
    vector<vector<int>> Max2;
    for (int i = 0; i < Min1.size(); i++) {
        pair<vector<int>, vector<int>> temp1 = solveLine(chage(Min1[i]));
        pair<vector<int>, vector<int>> temp2 = solveLine(chage(Max1[i]));
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
