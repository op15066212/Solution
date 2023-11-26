#include <bits/stdc++.h>

using namespace std;
#define int long long

//错
vector<int> getNext(const string &str) {
    int n = str.size();
    vector<int> next(n, 0);
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && str[i] != str[j]) {
            j = next[j - 1];
        }
        if (str[i] == str[j]) {
            j++;
            next[i] = j;
        }
    }
    return next;
}

// 使用KMP算法进行字符串匹配
vector<int> kmp(const string &a, const string &b) {
    if (a.size() < b.size()) {
        return {};
    }
    int n = (int) a.size();
    int m = (int) b.size();
    vector<int> res;
    vector<int> next = getNext(b);
    // 开始匹配
    for (int i = 0, j = 0; i < n; i++) {
        while (j - 1 >= 0 && a[i] != b[j]) {
            // 回溯到上一个元素的位置
            j = next[j - 1];
        }
        if (a[i] == b[j]) { // 模式字符串中字符匹配成功
            j++;
        }
        if (j == m) { // 找到完全匹配的位置索引
            res.push_back(i - j + 1);
            j = next[j - 1];  // 继续寻找下一个匹配
        }
    }
    return res;
}

void solve() {
    string str;
    cin >> str;
    vector<int> next = getNext(str);
    int back = next.back();

    string temp;
    for (int i = 0; i < back; i++) {
        temp += str[i];
    }
    while (!temp.empty() && kmp(str, temp).size() < 3) {
        temp.pop_back();
    }
    if (temp.empty()) {
        cout << "No" << '\n';
    } else {
        cout << temp << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
