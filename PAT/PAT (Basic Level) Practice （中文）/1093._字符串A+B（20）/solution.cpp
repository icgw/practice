#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    string s = s1 + s2;
    int hash[128] = { 0 };
    for (int i = 0; i < s.size(); ++i) {
        if (hash[s[i]] == 0) cout << s[i];
        hash[s[i]]++;
    }
    return 0;
}