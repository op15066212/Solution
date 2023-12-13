#include <bits/stdc++.h>

using namespace std;
#define int long long

class P {
public:
    int val{};
    int index{};

    P() = default;

    P(int val, int index) : val(val), index(index) {
    }
};

void solve() {
    int n;
    cin >> n;
    unordered_map<string, P> arr;
    for (int i = 0; i < n; i++) {
        string key;
        int val;
        cin >> key >> val;
        if (arr.find(key) == arr.end()) {
            arr[key] = {1000 + val, i};
        } else {
            arr[key] = {arr[key].val + val, i};
        }
    }
    string a;
    int b = INT_MAX;
    int minIndex = INT_MAX;
    for (const auto&[key, P]: arr) {
        int val = P.val;
        int index = P.index;
        if (val < b || (val == b && index < minIndex)) {
            b = val;
            a = key;
            minIndex = index;
        }
    }
    cout << a << "\n" << b << '\n';
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
