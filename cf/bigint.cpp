#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class BigInt {
private:
    string value;

public:
    BigInt(string val) : value(val) {}

    // 加法
BigInt operator+(const BigInt& b) const {
    string res = "";
    int carry = 0;
    string a = value;
    string b_value = b.value;  // 创建一个新的变量来存储 b 的值
    while (a.size() < b_value.size()) a = '0' + a;
    while (b_value.size() < a.size()) b_value = '0' + b_value;
    for (int i = a.size() - 1; i >= 0; i--) {
        int sum = a[i] - '0' + b_value[i] - '0' + carry;
        carry = sum / 10;
        res = char(sum % 10 + '0') + res;
    }
    if (carry) res = '1' + res;
    return BigInt(res);
}

// 减法
BigInt operator-(const BigInt& b) const {
    string res = "";
    int carry = 0;
    string a = value;
    string b_value = b.value;  // 创建一个新的变量来存储 b 的值
    for (int i = a.size() - 1; i >= 0; i--) {
        int diff = a[i] - '0' - carry;
        if (i < b_value.size()) diff -= b_value[i] - '0';
        if (diff >= 0) carry = 0;
        else {
            carry = 1;
            diff += 10;
        }
        res = char(diff + '0') + res;
    }
    while (res.size() > 1 && res[0] == '0') res = res.substr(1);
    return BigInt(res);
}


    // 乘法
    BigInt operator*(const BigInt& b) const {
        string res = "";
        for (int i = 0; i < value.size(); i++) {
            int carry = 0;
            string temp = string(value.size() - i - 1, '0');
            for (int j = b.value.size() - 1; j >= 0; j--) {
                int mul = (value[i] - '0') * (b.value[j] - '0') + carry;
                carry = mul / 10;
                temp = char(mul % 10 + '0') + temp;
            }
            if (carry) temp = char(carry + '0') + temp;
            res = (*this + BigInt(temp)).value;
        }
        return BigInt(res);
    }

    // 除法
    BigInt operator/(const BigInt& b) const {
        string res = "";
        string temp = "";
        for (int i = 0; i < value.size(); i++) {
            temp += value[i];
            int quotient = 0;
            while (BigInt(temp) >= b) {
                temp = (BigInt(temp) - b).value;
                quotient++;
            }
            res += char(quotient + '0');
        }
        while (res.size() > 1 && res[0] == '0') res = res.substr(1);
        return BigInt(res);
    }

    friend ostream& operator<<(ostream& os, const BigInt& b);
};

ostream& operator<<(ostream& os, const BigInt& b) {
    os << b.value;
    return os;
}
int main() {
    BigInt a("12345678901234567890");
    BigInt b("98765432109876543210");

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    BigInt sum = a + b;
    cout << "a + b = " << sum << endl;

    BigInt diff = a - b;
    cout << "a - b = " << diff << endl;

    BigInt product = a * b;
    cout << "a * b = " << product << endl;

    BigInt quotient = a / b;
    cout << "a / b = " << quotient << endl;

    return 0;
}
