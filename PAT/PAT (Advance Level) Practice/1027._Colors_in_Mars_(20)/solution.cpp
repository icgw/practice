#include <iostream>
using namespace std;

int main()
{
  string ch = "0123456789ABC";
  int RGB[3];
  cin >> RGB[0] >> RGB[1] >> RGB[2];
  cout << "#";
  for (int i = 0; i < 3; ++i) {
    cout << ch[RGB[i] / 13] << ch[RGB[i] % 13];
  }
  return 0;
}