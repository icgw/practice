#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    string max_id, min_id;
    int maxDist = -1, minDist = 9999;
    for (int i = 0; i < N; ++i) {
        string id;
        int x, y; cin >> id >> x >> y;
        int dis = x * x + y * y;
        if (dis > maxDist) {
            max_id = id;
            maxDist = dis;
        }
        if (dis < minDist) {
            min_id = id;
            minDist = dis;
        }
    }
    cout << min_id << " " << max_id << endl;
    return 0;
}