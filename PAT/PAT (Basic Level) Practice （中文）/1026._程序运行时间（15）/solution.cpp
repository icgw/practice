#include <iostream>
using namespace std;

int main() {
    int C1, C2;
    cin >> C1 >> C2;
    int n = (C2 - C1 + 50) / 100;
    int hour = n / 3600;
    n = n % 3600;
    int minute = n / 60;
    int second = n % 60;
    printf("%02d:%02d:%02d", hour, minute, second);
    return 0;
}