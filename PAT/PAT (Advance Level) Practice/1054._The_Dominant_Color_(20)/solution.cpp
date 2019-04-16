#include <iostream>
#include <map>
using namespace std;

int main()
{
    int m, n; cin >> m >> n;
    map<int, int> colors;
    int tmp;
    int half = (n * m) / 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> tmp;
            colors[tmp]++;
            if (colors[tmp] > half) {
                cout << tmp << endl;
                return 0;
            }
        }
    }
    return 0;
}