#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5 + 10;
vector<bool> mark(N, false);

void Prime() {
    for (int i = 2; i < N; i++) {
        for (int j = i; i * j < N; j++) {
            mark[i * j] = true;
        }
    }
    mark[0] = mark[1] = true;
}

void solve() {
    Prime();

    int num;
    cin >> num;
    if (mark[num]) {
        if (num % 2 == 0) {
            cout << "E" << endl;
        } else {
            cout << "O" << endl;
        }
    } else {
        cout << "P" << endl;
    }
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
