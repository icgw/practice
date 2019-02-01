#include <iostream>
using namespace std;

int main() {
  int A, B, D;
  cin >> A >> B >> D;
  int AB = A + B;
  if (AB == 0) {
    cout << 0;
    return 0;
  }
  int s[100];
  int i = 0;
  while (AB != 0) {
    s[i++] = AB % D;
    AB = AB / D;
  }
  
  for (int k = i - 1; k >= 0; --k) {
    cout << s[k];
  }
  
  return 0;
}