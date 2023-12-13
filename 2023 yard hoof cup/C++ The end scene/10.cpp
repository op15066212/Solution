#include <bits/stdc++.h>

using namespace std;
#define int long long

struct P {
    int index{};
    int val{};

    P() = default;

    P(long long index, long long val)
        : index(index),
          val(val) {
    }

    friend bool operator<(const P&lhs, const P&rhs) {
        if (lhs.val != rhs.val) {
            return lhs.val < rhs.val;
        }
        return lhs.index > rhs.index;
    }
};

int N;
int n;
priority_queue<P> arr;

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        arr.emplace(i + 1, val);
    }
    cin >> n;
    ostringstream oss;
    for (int i = 0; i < n; i++, arr.pop()) {
        oss << arr.top().index << ' ';
    }
    cout << oss.str() << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
