#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        sum += tmp * 10 * (N - 1) + tmp * (N - 1);
    }
    printf("%d", sum);
    return 0;
}