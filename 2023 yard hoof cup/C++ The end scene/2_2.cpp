#include <bits/stdc++.h>

using namespace std;
#define int long long

int find(const string&it) {
    int k = 0, i = 0, j = 0;
    int n = (int) it.size();
    while (k < n && i < n && j < n) {
        if (i == j) {
            j++;
        }
        if (it[(i + k) % n] == it[(j + k) % n]) {
            k++;
            continue;
        }
        it[(i + k) % n] > it[(j + k) % n] ? i += k + 1 : j += k + 1;
        k = 0;
    }
    return min(i, j);
}

void solve() {
    string A, B;
    cin >> A >> B;
    if (A.size() != B.size() || (A + A).find(B) == -1) {
        cout << "No" << endl;
        return;
    }
    int a = find(A);
    A = A.substr(a) + A.substr(0, a);
    cout << "Yes\n" + A << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
