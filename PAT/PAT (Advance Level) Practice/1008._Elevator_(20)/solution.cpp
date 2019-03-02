#include <iostream>
using namespace std;

int main() {
    int sum = 0, curr_floor = 0;
    int N; cin >> N;
    for (int i = 0; i < N; ++i) {
        int fw_floor;
        cin >> fw_floor;
        if (fw_floor > curr_floor) {
            sum += 6 * (fw_floor - curr_floor);
        } else {
            sum += 4 * (curr_floor - fw_floor);
        }
        curr_floor = fw_floor;
        sum += 5;
    }
    cout << sum << endl;
    return 0;
}