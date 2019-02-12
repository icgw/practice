#include <iostream>
#include <cctype>
using namespace std;

int main() {
    int n; cin >> n;
    cin.get(); // 把之前输入的回车符号过滤掉
    for (int i = 0; i < n; ++i) {
        string s; getline(cin, s);
        if (s.length() >= 6) {
            bool invalid, hasAlpha, hasDigit;
            invalid = hasAlpha = hasDigit = false;
            for (int k = 0; k < s.length(); ++k) {
                if (s[k] != '.' && !isalnum(s[k]))
                    invalid = true;
                else if (isalpha(s[k]))
                    hasAlpha = true;
                else if (isdigit(s[k]))
                    hasDigit = true;
            }
            if (invalid)
                cout << "Your password is tai luan le.\n";
            else if (!hasDigit)
                cout << "Your password needs shu zi.\n";
            else if (!hasAlpha)
                cout << "Your password needs zi mu.\n";
            else
                cout << "Your password is wan mei.\n";
        } else {
            cout << "Your password is tai duan le.\n";
        }
    }
    return 0;
}