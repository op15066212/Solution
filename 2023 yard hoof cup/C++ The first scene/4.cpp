#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> hashmap;
    int l = 0, r;
    int ans = 0;
    for (r = 0; r < n; r++) {
        int num = arr[r];
        hashmap[num]++;
        while (hashmap[num] > 1) {
            hashmap[arr[l++]]--;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
