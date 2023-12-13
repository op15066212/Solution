#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    string tmp, target;
    cin >> tmp >> target;
    string it;
    for (int i = 0; i < tmp.length(); i++) {
        if (tmp[i] != '!') {
            it += tmp[i];
        }
    }
    if (it.find(target) != -1) {
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
