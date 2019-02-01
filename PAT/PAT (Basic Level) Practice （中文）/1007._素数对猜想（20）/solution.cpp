#include <iostream>
using namespace std;

bool isPrime(int n){
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int main(){
  int N; cin >> N;
  int cnt = 0;
  for (int i = 5; i <= N; ++i) {
    if (isPrime(i - 2) && isPrime(i)) cnt++;
  }
  cout << cnt;
  return 0;
}