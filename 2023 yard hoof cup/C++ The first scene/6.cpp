#include <bits/stdc++.h>

using namespace std;
#define int long long

//错
char change(const char &c) {
    if (c == 'A') {
        return 'B';
    } else {
        return 'A';
    }
}

int dfs(string str) {
    int a = 0;
    int b = 0;
    char temp = 'A';
    for (int i = 0; i < str.size(); i++, temp = change(temp)) {
        if (str[i] != temp) {
            a++;
        }
        if (str[i] != change(temp)) {
            b++;
        }
    }
    return min(a, b);
}

void solve() {
    int n;
    cin >> n;
    vector<string> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    ostringstream oss;
    for (const auto &str: data) {
        int cnt = dfs(str);
        oss << cnt << "\n";
    }
    cout << oss.str();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
