#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> say(N + 1);
  for (int i = 1; i <= N; ++i) cin >> say[i];
  
  vector<int> isTrue(N + 1, 1);
  for (int i = 1; i <= N; ++i) {
    isTrue[i] = -1;
    for (int j = i + 1; j <= N; ++j) {
      isTrue[j] = -1;
      vector<int> Liar;
      for (int k = 1; k <= N; ++k) {
        if (say[k] * isTrue[abs(say[k])] < 0) Liar.push_back(k);
      }
      
      if (Liar.size() == 2 && isTrue[Liar[0]] + isTrue[Liar[1]] == 0) {
        printf("%d %d\n", i, j);
        return 0;
      }
      
      isTrue[j] = 1;
    }
    isTrue[i] = 1;
  }
  printf("No Solution\n");
  return 0;
}