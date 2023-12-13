#include <bits/stdc++.h>

using namespace std;
#define int long long

bool check(int bas,int num) {
    if (num % bas == 0) {
        return true;
    }
    unordered_set<int> st;
    while (num > 0) {
        st.insert(num % 10);
        num /= 10;
    }
    return st.find(bas) != st.end();
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(3, 0);
    for (int i = 1; i <= n; i++) {
        if (check(3, i)
            && check(5, i)) {
            a[2]++;
        } else if (check(5, i)) {
            a[1]++;
        } else if (check(3, i)) {
            a[0]++;
        }
    }
    for (long long i: a) {
        cout << i << "\n";
    }
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
