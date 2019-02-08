#include <iostream>
using namespace std;

int main() {
    int M, N, A, B, D;
    scanf("%d%d%d%d%d", &M, &N, &A, &B, &D);
    int tmp;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &tmp);
            if (j != 0) printf(" ");
            if (tmp >= A && tmp <= B) tmp = D;
            printf("%03d", tmp);
        }
        printf("\n");
    }
    return 0;
}