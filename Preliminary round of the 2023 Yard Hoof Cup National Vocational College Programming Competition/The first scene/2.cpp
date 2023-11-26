#include <bits/stdc++.h>

using namespace std;
#define int long long

int check(int i) {
    if (i % 2 == 0 && i % 3 == 0) {
        return i;
    }
    return 0;
}

void solve() {
    string str;
    cin >> str;
    stringstream ss(str);
    vector<string> data;
    string temp;
    while (getline(ss, temp, ',')) {
        data.push_back(temp);
    }
    int n = stoll(data[0]);
    int N = stoll(data[1]);
    int ans = 0;
    for (int i = n; i <= N; i++) {
        ans += check(i);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
