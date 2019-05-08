#include <iostream>
using namespace std;

int main()
{
    string input;
    cin >> input;
    int num = 0;
    for (auto ch : input) {
        num += (ch - '0');
    }
    string sum = to_string(num);

    static string digits[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    int sz = sum.size();
    for (int i = 0; i < sz; ++i) {
        if (i != 0) cout << " ";
        cout << digits[sum[i] - '0'];
    }

    return 0;
}