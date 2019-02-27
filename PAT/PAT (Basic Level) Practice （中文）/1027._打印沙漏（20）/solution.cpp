#include <iostream>
using namespace std;

int main() {
    int N; char ch; cin >> N >> ch;
    int row = 0;
    for (int i = 1; i <= N + 1; ++i) {
        if (2 * i * i - 1 > N) {
            row = i - 1;
            break;
        }
    }

    int space_nums = 0;
    for (int i = 2 * row - 1; i >= 1; i -= 2, ++space_nums) {
        for (int k = 0; k < space_nums; ++k) cout << " ";
        for (int k = 0; k < i; ++k) cout << ch;
        cout << endl;
    }

    space_nums -= 2;
    for (int i = 3; i <= 2 * row - 1; i += 2, --space_nums) {
        for (int k = 0; k < space_nums; ++k) cout << " ";
        for (int k = 0; k < i; ++k) cout << ch;
        cout << endl;
    }

    int remain = row > 0 ? ((2 * row) * row - 1) : 0;
    cout << N - remain << endl;
    return 0;
}