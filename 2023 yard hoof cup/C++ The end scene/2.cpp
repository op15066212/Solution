#include <bits/stdc++.h>

using namespace std;
#define int long long

string A, B;
string res;
deque<char> it;
deque<char> mi;

void round() {
    char temp = it.front();
    it.pop_front();
    it.push_back(temp);
}

bool find() {
    for (int i = 0; i < it.size(); i++) {
        if (mi[i] > it[i]) {
            return true;
        }
        if (mi[i] < it[i]) {
            return false;
        }
    }
    return false;
}

void check() {
    if (A.size() != B.size()) {
        res = "No";
        return;
    }
    A += A;
    if (A.find(B) == -1) {
        res = "No";
        return;
    }
    for (const auto&c: B) {
        it.push_back(c);
        mi.push_back(c);
    }
    int n = (int) A.size();
    for (int i = 0; i < n; i++, round()) {
        if (find()) {
            mi = it;
        }
    }
    string ans;
    for (const auto&i: mi) {
        ans += i;
    }
    res = "Yes\n" + ans;
}

void solve() {
    cin >> A >> B;
    check();
    cout << res << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
