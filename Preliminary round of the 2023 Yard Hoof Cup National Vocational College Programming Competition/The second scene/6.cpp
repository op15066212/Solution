#include <bits/stdc++.h>

//错
using namespace std;
#define int long long

struct P {
    int L{}, Max{}, S{};

    P() = default;

    P(long long l, long long max, long long s)
        : L(l),
          Max(max),
          S(s) {
    }
};

struct Q {
    int P{}, C{};

    Q() = default;

    Q(long long p, long long c)
        : P(p),
          C(c) {
    }

    friend bool operator<(const Q&lhs, const Q&rhs) {
        if (lhs.P < rhs.P)
            return true;
        if (rhs.P < lhs.P)
            return false;
        return lhs.C < rhs.C;
    }
};

struct node {
    int distance{}, money{}, id{};

    node() = default;

    node(long long distance, long long money, long long id)
        : distance(distance),
          money(money),
          id(id) {
    }
};

// N个加油站
// L路程
// Max油量
// S钱

// P加油站位置
// C加油钱

// distance走了多少距离
// money还有多少钱
// id第几个加油站

int n;
P now;

string bfs(const vector<Q>&tp) {
    queue<node> queue;
    int L = now.L;
    int Max = now.Max;
    int money = now.S;
    queue.emplace(0, money, 0);
    while (!queue.empty()) {
        node it = queue.front();
        queue.pop();
        // 油量足够到终点
        if (L - it.distance <= Max) {
            return "Yes";
        }
        for (int i = it.id; i < n; i++) {
            // 油量无法到加油站
            if (tp[i].P - it.distance > Max) {
                break;
            }
            int mod = it.money - tp[i].C;
            // 还剩的有钱
            if (mod >= 0) {
                queue.emplace(tp[i].P, mod, i);
            }
        }
    }
    return "No";
}

void solve() {
    int max, L, S;
    while (cin >> n >> L >> max >> S) {
        now = P(L, max, S);
        vector<Q> tp(n);
        for (int i = 0; i < n; i++) {
            cin >> tp[i].P >> tp[i].C;
        }
        sort(tp.begin(), tp.end());
        cout << bfs(tp) << endl;
    }
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
