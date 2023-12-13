#include <bits/stdc++.h>

using namespace std;
#define int long long

string A;

void change(string&it) {
    if (it[0] >= '0' && it[0] <= '9') {
        int num = stoll(it);
        string res;
        for (; num > 0; num /= 26) {
            res += char(num % 26 + 'a');
        }
        reverse(res.begin(), res.end());
        it = res;
    } else {
        int num = 0;
        int bas = 1;
        for (int i = (int) it.size() - 1; i >= 0; i--, bas *= 26) {
            num += bas * (it[i] - 'a');
        }
        it = to_string(num);
    }
}

int next(int i) {
    int p1;
    int p2;
    for (p1 = i; p1 < A.size() && A[p1] >= '0' && A[p1] <= '9'; p1++) {
    }
    for (p2 = i; p2 < A.size() && A[p2] >= 'a' && A[p2] <= 'z'; p2++) {
    }
    return max(p1, p2);
}

void solve() {
    cin >> A;
    string res;
    for (int i = 0; i < A.size(); i = next(i)) {
        int j = next(i);
        string temp = A.substr(i, j - i);
        change(temp);
        res += temp;
    }
    cout << res << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
