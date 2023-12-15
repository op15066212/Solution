#include <bits/stdc++.h>

using namespace std;

int k;

class BigInteger {
public:
    string data;
    bool sign; // 符号：true 表示为正数，false 表示为负数
    BigInteger() {
        data = "0";
        sign = true;
        clear();
    }

    // 构造函数
    explicit BigInteger(string s) {
        int i = 0;
        while (s[i] == '-') {
            i++;
        }
        if (i % 2 == 0) {
            sign = true;
        } else {
            sign = false;
        }
        s = s.substr(i);
        data = s;
        clear();
    }

    // 构造函数
    explicit BigInteger(int n) {
        string s = to_string(n);
        int i = 0;
        while (s[i] == '-') {
            i++;
        }
        if (i % 2 == 0) {
            sign = true;
        } else {
            sign = false;
        }
        s = s.substr(i);
        data = s;
        clear();
    }

    // 构造函数
    explicit BigInteger(long n) {
        string s = to_string(n);
        int i = 0;
        while (s[i] == '-') {
            i++;
        }
        if (i % 2 == 0) {
            sign = true;
        } else {
            sign = false;
        }
        s = s.substr(i);
        data = s;
        clear();
    }

    [[nodiscard]] int size() const {
        return (int) data.size();
    }

    void clear() {
        clearT(data);
        if (data == "0") {
            sign = true;
        }
    }

    static void clearK(string&str) {
        int n = (int) str.size();
        if (2 * k >= n) {
            return;
        }
        string copy;
        for (int i = 0; i < 2 * k && i < n; i++) {
            copy += str[n - 1 - i];
        }
        reverse(copy.begin(), copy.end());
        str = copy;
    }

    static void clearT(string&str) {
        clearK(str);
        if (str.empty()) {
            str = "0";
            return;
        }
        int i = 0;
        while (i < str.size() - 1 && str[i] == '0') {
            i++;
        }
        str = str.substr(i);
    }

    static string multiplyAbs(string a, string b) {
        clearT(a);
        clearT(b);
        int len1 = (int) a.size();
        int len2 = (int) b.size();
        string res(len1 + len2, '0');
        for (int i = len1 - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = len2 - 1; j >= 0; j--) {
                carry += (a[i] - '0') * (b[j] - '0') + (res[i + j + 1] - '0');
                res[i + j + 1] = (char) (carry % 10 + '0');
                carry /= 10;
            }
            res[i] = (char) (res[i] + carry);
        }
        clearT(res);
        return res;
    }

    // 封装乘法方法，返回一个新的 BigInteger 类型
    [[nodiscard]] BigInteger multiply(const BigInteger&num) const {
        if (sign == num.sign) {
            return BigInteger(multiplyAbs(data, num.data));
        } else {
            return BigInteger("-" + multiplyAbs(data, num.data));
        }
    }

    [[nodiscard]] BigInteger pow(long long num) const {
        BigInteger res(1);
        BigInteger bas = *this;
        while (num > 0) {
            if (num % 2 == 1) {
                res *= bas;
            }
            bas *= bas;
            num /= 2;
        }
        return res;
    }

    // 重载乘法运算符 *
    BigInteger operator*(const BigInteger&num) const {
        return multiply(num);
    }

    void operator*=(const BigInteger&num) {
        *this = *this * num;
    }

    char& operator[](int index) {
        return data[index];
    }

    friend istream& operator>>(istream&is, BigInteger&num) {
        string s;
        is >> s;
        num = BigInteger(s);
        return is;
    }

    // 重载输出运算符 <<，输出格式同上
    friend ostream& operator<<(ostream&os, const BigInteger&num) {
        os << num.data;
        return os;
    }
};

void solve() {
    string it;
    cin >> it >> k;
    BigInteger n(it);
    BigInteger mul = n;
    BigInteger ans(1);
    for (int i = 0; i < k; i++) {
        BigInteger temp = n;
        bool notfound = true;
        int j = 1;
        for (; j <= 10; j++) {
            temp *= mul;
            if (temp[temp.size() - 1 - i] == n[n.size() - 1 - i]) {
                ans *= BigInteger(j);
                notfound = false;
                break;
            }
        }
        if (notfound) {
            cout << "-1" << endl;
            return;
        }
        mul = mul.pow(j);
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
