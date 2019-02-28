#include <iostream>
#include <set>
using namespace std;

int getFnum(int n) {
    int ret = 0;
    while (n != 0) {
        ret += (n % 10);
        n /= 10;
    }
    return ret;
}

int main() {
    int N; cin >> N;
    set<int> s;
    for (int i = 0; i < N; ++i) {
        int tmp; cin >> tmp;
        s.insert(getFnum(tmp));
    }
    
    cout << s.size() << endl;
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (it != s.begin()) cout << " ";
        cout << *it;
    }
    cout << endl;
    
    return 0;
}