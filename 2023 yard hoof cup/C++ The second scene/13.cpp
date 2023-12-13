#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    unordered_set<int> myset;

    int m;
    while (cin >> m) {
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            myset.insert(temp);
        }
    }

    if (myset.size() == n) {
        cout << "It Takes Two." << endl;
    } else {
        cout << "Maybe Next Time." << endl;
    }
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
