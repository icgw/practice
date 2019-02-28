#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); ++i) {
        for (int j = 0; j < s2.size(); ++j) {
            if (s1[i] == '#' || s2[j] == '#') continue;
            if (s1[i] == s2[j]) {
                s1[i] = s2[j] = '#';
            }
        }
    }
    
    int r = 0, lack = 0;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != '#') r++;
    }
    
    for (int i = 0; i < s2.size(); ++i) {
        if (s2[i] != '#') lack++;
    }
    
    if (lack == 0) {
        cout << "Yes " << r << endl;
    } else {
        cout << "No "  << lack << endl;
    }
    
    return 0;
}