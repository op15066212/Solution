#include <bits/stdc++.h>

using namespace std;
#define int long long

string p, q;

int gcd(int a,int b) {
    int mod = a % b;
    if (mod == 0) {
        return b;
    }
    return gcd(b, mod);
}

void round(string&it) {
    char tmp = it[0];
    it.erase(it.begin());
    it += tmp;
}

int dfs() {
    int res = 0;
    unordered_set<string> st;
    while (gcd(stoll(p), stoll(q)) != 1) {
        if (st.find(p) != st.end()) {
            return -1;
        }
        st.insert(p);
        round(p), round(q);
        res++;
    }
    return res;
}

void solve() {
    cin >> p >> q;
    if (p.size() < q.size()) {
        swap(p, q);
    }
    cout << dfs() << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
