#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    map<char,int> mp;
    string dat;
    cin >> dat;
    for (const auto&it: dat) {
        mp[it]++;
    }
    char res = 'A';
    int mx = INT_MIN;
    for (const auto&[key, val]: mp) {
        if (val > mx) {
            mx = val;
            res = key;
        }
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
