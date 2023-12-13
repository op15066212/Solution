#include <bits/stdc++.h>

using namespace std;
#define int long long

//错
void solve() {
    map<int, int> mp;
    int x = 0;
    for (int i = 0; i < 5; i++) {
        cin >> x;
        mp[x]++;
    }

    int sum1 = 0;
    int sum2 = 0;
    for (const auto &[key, val]: mp) {
        if (val >= 4) {
            sum1++;
        } else if (val >= 2) {
            sum2++;
        }
    }
    if (sum1 >= 1) {
        cout << "Square" << '\n';
    } else if (sum2 >= 2) {
        cout << "Rectangle" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
