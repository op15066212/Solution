#include <ostream>
#include <bits/stdc++.h>

using namespace std;
#define int long long

struct P {
    int key;
    int val;

    P(int key, int val) : key(key), val(val) {
    };

    friend std::ostream& operator<<(std::ostream&os, const P&obj) {
        return os
               << "key: " << obj.key
               << " val: " << obj.val;
    }
};


vector<pair<int,int>> da;
map<int, int> mp;
vector<P> diff;
int n;

void getdiff() {
    for (const auto&[a, b]: da) {
        mp[a]++;
        mp[b + 1]--;
    }
    int sum = 0;
    for (const auto&[a, b]: mp) {
        sum += b;
        diff.emplace_back(a, sum);
    }
}

void init() {
    cin >> n;
    da.assign(n, {});

    for (int i = 0; i < n; i++) {
        cin >> da[i].first >> da[i].second;
    }
    getdiff();
}

pair<int,int> getRes() {
    int ans1 = 0, ans2 = 0;
    int s1 = INT_MAX, s2 = INT_MAX;
    for (const auto&[key, val]: diff) {
        if (val != 0) {
            if (s1 == INT_MAX) {
                s1 = key;
            }

            ans2 = max(ans2, key - s2);
            s2 = INT_MAX;
        } else {
            if (s2 == INT_MAX) {
                s2 = key;
            }

            ans1 = max(ans1, key - s1);
            s1 = INT_MAX;
        }
    }
    if (ans1 != 0) {
        ans1--;
    }
    if (ans2 != 0) {
        ans2++;
    }
    return {ans1, ans2};
}


void solve() {
    init();
    pair<int, int> res = getRes();
    cout << res.first << " " << res.second << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
