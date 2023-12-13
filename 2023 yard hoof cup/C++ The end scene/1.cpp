#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, t;
vector<int> arr;

void solve() {
    cin >> n >> t;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int day = 0;
    for (int i = 0; i < n && t > 0; i++, day++) {
        int diff = 1440 - arr[i];
        if (diff >= 60) {
            t -= diff;
        }
    }
    cout << day << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
