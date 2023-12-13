#include <bits/stdc++.h>

using namespace std;
#define int long long

int n;
vector<int> arr;

bool check() {
    for (int i = 2; i < n; i++) {
        if (arr[i - 2] < arr[i - 1] && arr[i - 1] < arr[i]) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (check()) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
