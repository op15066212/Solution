#include <bits/stdc++.h>

using namespace std;
#define int long long

int S(const string& st, char key) {
    int index = st.find(key);
    return index == -1 ? -1 : index + 1;
}

void solve() {
    string st;
    char key;
    cin >> st >> key;
    cout << S(st, key) << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
