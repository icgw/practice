#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    int E = 0;
    while (s[E] != 'E') E++;
    string L = s.substr(1, E - 1);
    int n = stoi(s.substr(E + 1));
    if (s[0] == '-') cout << "-";
    if (n < 0) {
        cout << "0.";
        for (int i = 0; i < abs(n) - 1; ++i) cout << "0";
        for (int i = 0; i < L.size(); ++i) if (L[i] != '.') cout << L[i];
    } else {
        int i, cnt;
        cout << L[0];
        for (i = 2, cnt = 0; i < L.size() && cnt < n; ++i, ++cnt) cout << L[i];
        if (i == L.size()) {
            for ( ; cnt < n; ++cnt) cout << "0";
        } else {
            cout << ".";
            for ( ; i < L.size(); ++i) cout << L[i];
        }
    }
    return 0;
}