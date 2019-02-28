#include <iostream>
using namespace std;

int main(){
    int teams[1001] = { 0 };
    int N; 
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int tid, pid, score;
        scanf("%d-%d %d", &tid, &pid, &score);
        teams[tid] += score;
    }
    
    int id_for_max = 1;
    for (int i = 1; i < 1001; ++i) {
        if (teams[i] > teams[id_for_max]) {
            id_for_max = i;
        }
    }
    
    printf("%d %d\n", id_for_max, teams[id_for_max]);
    return 0;
}