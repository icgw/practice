#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  float ans = 1.0;
  for (int i = 0; i < 3; ++i) {
    float W, T, L;
    cin >> W >> T >> L;
    if (W >= T && W >= L) {
      ans *= W;
      cout << "W ";
    }
    else if (T >= W && T >= L) {
      ans *= T;
      cout << "T ";
    }
    else if (L >= T && L >= W) {
      ans *= L;
      cout << "L ";
    }
  }
  cout << setiosflags(ios::fixed);
  cout << setprecision(2) << (ans * 0.65 - 1) * 2.0 << endl;
  return 0;
}