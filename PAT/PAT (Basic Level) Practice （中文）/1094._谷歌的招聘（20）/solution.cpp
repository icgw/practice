#include <iostream>
using namespace std;

bool isPrime(int n) {
  if (n == 0 || n == 1) return false;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int L, K; cin >> L >> K;
  string num; cin >> num;
  for (int i = 0; i <= L - K; ++i) {
    string t = num.substr(i, K);
    int n = stoi(t);
    if (isPrime(n)) {
      cout << t;
      return 0;
    }
  }
  cout << "404";
  return 0;
}