#include <iostream>
using namespace std;

int main()
{
    int g1, s1, k1, g2, s2, k2;
    char omit;
    cin >> g1 >> omit >> s1 >> omit >> k1;
    cin >> g2 >> omit >> s2 >> omit >> k2;

    int g, s, k;
    k = (k1 + k2);
    s = k / 29 + s1 + s2;
    k %= 29;
    g = s / 17 + g1 + g2;
    s %= 17;
    cout << g << "." << s << "." << k << "\n";

    return 0;
}