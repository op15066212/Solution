#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    string str;
    cin >> str;
    vector<char> arr;
    for (const auto &c: str) {
        arr.push_back(c);
    }
    sort(arr.begin(), arr.end());
    cout << arr.back() << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
