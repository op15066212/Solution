#include <bits/stdc++.h>

using namespace std;
#define int long long

int n;

void solve() {
    cin >> n;
    int ans = 0;
    // ans += 6 * (n / a / b - b) 是 a != b && b != c, 也就是 a * b * c <= n, a > b > c。
    // ans += 3 * (n / a / a - a) 是两大一小，也是就是 a * a * b <= n，a > b。
    // ans += 3 * (sqrt(n / a) - a) 是两小一大，也就是 a * b * b <= n, a > b。
    // ans += 1 是 a == b && b == c。
    //
    // a * b * c <= n 变化一下就是 c <= n / a / b
    // a * a * b <= n 变化一下就是 b <= n / a / a
    // a * b * b <= n 变化一下就是 b <= sqrt(n / a)
    for (int a = 1; a * a * a <= n; a++) {
        ans += 3 * (n / a / a - a);
        ans += 3 * ((int) sqrt(n / a) - a);
        ans += 1;
        for (int b = a + 1; a * b * b <= n; b++, ans %= 3333) {
            ans += 6 * (n / a / b - b);
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
