#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    string cnt = "";
    for (int i = 0; i < s1.size(); ++i) {
        if (s2.find(s1[i]) == string::npos &&
        cnt.find(toupper(s1[i])) == string::npos) {
            cnt += toupper(s1[i]);
        }
    }
    cout << cnt << endl;
    
    return 0;
}