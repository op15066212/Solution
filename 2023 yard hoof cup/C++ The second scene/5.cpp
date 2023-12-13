#include <bits/stdc++.h>

using namespace std;
#define int long long

void clearZero(string&num) {
    int i = 0;
    while (i < num.size() - 1 && num[i] == '0') {
        i++;
    }
    num = num.substr(i);
}

void solve() {
    string num1;
    cin >> num1;
    string num2 = num1;
    reverse(num2.begin(), num2.end());
    clearZero(num1);
    clearZero(num2);
    int a = stoll(num1);
    int b = stoll(num2);
    if (b < a) {
        cout << num2 << "\n";
        cout << "False" << endl;
    } else {
        cout << num2 << "\n";
        cout << "True" << endl;
    }
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
