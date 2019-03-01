#include <iostream>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int teacher; cin >> teacher;
        int group = 0;
        int valids = -2;
        int minScore = m, maxScore = 0;
        for (int j = 1; j < n; ++j) {
            int g; cin >> g;
            if (g >= 0 && g <= m) {
                group += g;
                valids++;
                if (g > maxScore) {
                    maxScore = g;
                }
                if (g < minScore) {
                    minScore = g;
                }
            }
        }
        cout << (int)(((group - minScore - maxScore) * 1.0 / valids + teacher) / 2 + 0.5) << endl;
    }
    return 0;
}