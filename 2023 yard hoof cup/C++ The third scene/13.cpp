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
    unordered_set<char> mp;
    for (int i = 0; i < n; i++) {
        if (mp.find(box[i][i]) != mp.end()) {
            cout << "refuse" << endl;
            return;
        }
        mp.insert(box[i][i]);
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
