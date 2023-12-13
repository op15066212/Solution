#include <bits/stdc++.h>

using namespace std;
#define int long long

const int n = 1000;
const int m = 1000;
int N;
unordered_map<int, unordered_set<int>> mp;

int dfs() {
    int res = 0;
    int start = 0;
    int end = 499;
    for (int i = 0; i < n; i++) {
        if (end < 0) {
            end = 0;
        }
        if (end > 999) {
            end = 999;
        }
        res += (end - start + 1);
        int temp = 0;
        if (mp.find(i) != mp.end()) {
            for (const auto&it: mp[i]) {
                if (end >= it) {
                    temp += (i - it);
                }
            }
        }
        end += temp;
    }
    return res;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        mp[a].emplace(b);
    }
    cout << dfs() << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
