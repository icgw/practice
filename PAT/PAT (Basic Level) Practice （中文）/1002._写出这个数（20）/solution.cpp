#include <iostream>
#include <string>
using namespace std;
const static string str[10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
int main() {
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < s.length(); ++i)
        sum += (s[i] - '0');
    string num = to_string(sum);
    for (int i = 0; i < num.length(); ++i) {
        if (i != 0) cout << " ";
        cout << str[num[i] - '0'];
    }
    return 0;
}
