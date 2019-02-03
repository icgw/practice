#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int head, N, K;
    cin >> head >> N >> K;
    int dt[100005], nxt[100005], lst[100005];
    for (int i = 0; i < N; ++i) {
        int tmp; cin >> tmp;
        cin >> dt[tmp] >> nxt[tmp];
    }
    int first = head;
    int j = 0;
    while (first != -1) {
        lst[j++] = first;
        first = nxt[first];
    }
    
    for (int i = 0; i < j - j % K; i += K)
        reverse(begin(lst) + i, begin(lst) + i + K);
    
    for (int i = 0; i < j - 1; ++i) {
        printf("%05d %d %05d\n", lst[i], dt[lst[i]], lst[i + 1]);
    }
    printf("%05d %d -1", lst[j - 1], dt[lst[j - 1]]);
    
    return 0;
}