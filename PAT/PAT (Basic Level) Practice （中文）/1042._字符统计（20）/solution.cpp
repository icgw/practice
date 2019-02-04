#include <iostream>
#include <cctype>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i) s[i] = tolower(s[i]);
    int alpha[26] = { 0 };
    for (int i = 0; i < s.size(); ++i)
        if (islower(s[i])) alpha[s[i] - 'a']++;
    int maxCount = 0, idx;
    for (int i = 0; i < 26; ++i) {
        if (alpha[i] > maxCount) {
            maxCount = alpha[i];
            idx = i;
        }
    }
    printf("%c %d", idx + 'a', maxCount);
    return 0;
}