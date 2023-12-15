#include <bits/stdc++.h>

using namespace std;
#define int long long

int n, k, L, R;
vector<int> sum;
vector<vector<int>> F;

void createST() {
    for (int i = 1; i <= n; i++) {
        F[i][0] = i;
    }
    int k = (int) log2(n);
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            int x = F[j][i - 1];
            int y = F[j + (1 << i - 1)][i - 1];
            F[j][i] = sum[x] > sum[y] ? x : y;
        }
    }
}

int queryST(int l, int r) {
    int k = (int) log2(r - l + 1);
    int x = F[l][k];
    int y = F[r - (1 << k) + 1][k];
    return sum[x] > sum[y] ? x : y;
}

struct node {
    int start{};
    int l{};
    int r{};
    int maxIndex{};

    node() = default;

    node(long long start, long long l, long long r)
        : start(start), l(l), r(r) {
        maxIndex = queryST(l, r);
    }

    [[nodiscard]] int get() const {
        return sum[maxIndex] - sum[start - 1];
    }

    bool operator<(const node&other) const {
        return get() < other.get();
    }
};

void solve() {
    cin >> n >> k >> L >> R;
    sum.assign(n + 1, 0);
    F.assign(n + 1, vector<int>((int) log2(n) + 1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    createST();
    priority_queue<node> queue;
    for (int i = 1; i <= n; i++) {
        if (i + L - 1 <= n) {
            queue.emplace(i, i + L - 1, min(i + R - 1, n));
        }
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        node it = queue.top();
        queue.pop();
        ans += it.get();
        if (it.maxIndex > it.l) {
            queue.emplace(it.start, it.l, it.maxIndex - 1);
        }
        if (it.maxIndex < it.r) {
            queue.emplace(it.start, it.maxIndex + 1, it.r);
        }
    }
    cout << ans << endl;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
