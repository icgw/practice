#include <iostream>
#include <cctype>
using namespace std;

void countZeroOne(int n, int &zero, int &one){
    zero = one = 0;
    while (n != 0) {
        if (n & 1) {
            one++;
        } else {
            zero++;
        }
        n >>= 1;
    }
    return ;
}

int main() {
    string s;
    getline(cin, s);
    int n = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (!isalpha(s[i])) continue;
        n += (int) (tolower(s[i]) - 'a' + 1);
    }
    
    int zero, one;
    countZeroOne(n, zero, one);
    cout << zero << " " << one << endl;
    
    return 0;
}