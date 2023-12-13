#include <bits/stdc++.h>

using namespace std;
#define int long long

string A;

bool check() {
    if (A.size() <= 6) {
        return false;
    }
    set<char> s1;
    set<char> s2;
    set<char> s3;
    for (const char c: A) {
        if (c >= 'a' && c <= 'z') {
            s1.insert(c);
        }
        if (c >= 'A' && c <= 'Z') {
            s2.insert(c);
        }
        if (c >= '0' && c <= '9') {
            s3.insert(c);
        }
    }
    if (s1.size() == 0 || s2.size() == 0 || s3.size() == 0) {
        return false;
    }
    for (int i = 1; i < A.size(); i++) {
        if (A[i - 1] >= '0' && A[i - 1] <= '9'
            && A[i] >= '0' && A[i] <= '9') {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> A;
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
