#include <bits/stdc++.h>

#include <utility>

using namespace std;
#define int long long

struct P {
    string key{};
    vector<int> index{};

    P() = default;

    P(string key, const vector<long long>&index)
        : key(std::move(key)),
          index(index) {
    }

    friend bool operator<(const P&lhs, const P&rhs) {
        return lhs.index[0] < rhs.index[0];
    }
};

void show(const vector<P>&res) {
    ostringstream oss;
    for (const auto&[key,val]: res) {
        oss << key << "(";
        for (int i = 0; i < val.size() - 1; i++) {
            oss << val[i] << ",";
        }
        oss << val[val.size() - 1] << ")";
    }
    cout << oss.str() << endl;
}

void solve() {
    int n;
    cin >> n;
    unordered_map<string, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        string key;
        cin >> key;
        mp[key].push_back(i + 1);
    }
    vector<P> res;
    for (const auto&[key,val]: mp) {
        res.emplace_back(key, val);
    }
    sort(res.begin(), res.end());
    show(res);
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
