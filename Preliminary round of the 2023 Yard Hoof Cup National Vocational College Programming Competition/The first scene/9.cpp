#include <bits/stdc++.h>

using namespace std;
#define int long long

string change(const string &s) {
    if (s.size() % 2 == 1) {
        return "123456";
    }
    int m = (int) s.size() / 2;
    string a = s.substr(0, m);
    string b = s.substr(m);
    reverse(b.begin(), b.end());
    return a + b;
}

void solve() {
    string s;
    cin >> s;
    cout << change(s) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
