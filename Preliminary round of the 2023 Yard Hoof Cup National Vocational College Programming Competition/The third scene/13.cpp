#include <bits/stdc++.h>

using namespace std;
#define int long long

vector<string> box;

void solve() {
    int n;
    cin >> n;
    box.assign(n, "");
    for (int i = 0; i < n; i++) {
        cin >> box[i];
    }
    unordered_set<char> mp1;
    unordered_set<char> mp2;
    for (int i = 0; i < n; i++) {
        if (mp1.find(box[i][i]) != mp1.end()) {
            cout << "refuse" << endl;
            return;
        }
        mp1.insert(box[i][i]);
    }
    for (int i = 0; i < n; i++) {
        if (mp2.find(box[i][n - 1 + i]) != mp2.end()) {
            cout << "refuse" << endl;
            return;
        }
    }
    cout << "accept" << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
