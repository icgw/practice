#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double R1, P1, R2, P2;
  cin >> R1 >> P1 >> R2 >> P2;
  double R12 = R1 * R2;
  double A = R12 * cos(P1) * cos(P2) - R12 * sin(P1) * sin(P2);
  double B = R12 * cos(P1) * sin(P2) + R12 * sin(P1) * cos(P2);
  
  if (abs(A) < 0.005)
    printf("0.00");
  else
    printf("%.2f", A);
  
  if (abs(B) < 0.005)
    printf("+0.00i");
  else if (B >= 0)
    printf("+%.2fi", B);
  else
    printf("%.2fi", B);
  
  return 0;
}