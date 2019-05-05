#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    char colon;
    int h1, m1, s1, h2, m2, s2;
    string id;
    string unlocked, locked;
    int mint = 24 * 3600, maxt = 0;
    for (int i = 0; i < N; ++i) {
        cin >> id;
        cin >> h1 >> colon >> m1 >> colon >> s1;
        int start = h1 * 3600 + 60 * m1 + s1;
        if (start < mint) {
            mint = start;
            unlocked = id;
        }
        cin >> h2 >> colon >> m2 >> colon >> s2;
        int end = h2 * 3600 + 60 * m2 + s2;
        if (end > maxt) {
            maxt = end;
            locked = id;
        }
    }
    cout << unlocked << " " << locked << "\n";
    return 0;
}