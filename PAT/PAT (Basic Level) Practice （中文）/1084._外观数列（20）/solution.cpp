#include <iostream>
using namespace std;

int main() {
    string s;
    int N; cin >> s >> N;
    for (int i = 1; i < N; ++i) {
        string t;
        for (int j = 0, k = 0; j < s.size(); j = k) {
            for (k = j; k < s.size() && s[k] == s[j]; ++k);
            t += (s[j] + to_string(k - j));
        }
        s = t;
    }
    cout << s << endl;
    return 0;
}