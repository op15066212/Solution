#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    string str;
    cin >> str;
    int size = (int) str.size();
    int maxLen = 0;
    for (int i = size - 1; i > -1 && (str[i] - '0') == 0; i--, maxLen++) {}
    string res = to_string(str[0] - '0');
    if (maxLen != size - 1) {
        res += '.';
    }
    res += str.substr(1, size - maxLen - 1);
    if (size != 1) {
        res += "E" + to_string(size - 1);
    }
    cout << res << '\n';
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
