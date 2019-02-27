#include <iostream>
using namespace std;

int main() {
    int T, K; cin >> T >> K;
    for (int i = 0; i < K; ++i) {
      int n1, b, t, n2;
      cin >> n1 >> b >> t >> n2;
      if (T == 0) {
        cout << "Game Over.\n";
        return 0;
      }
    
      if (t > T) {
        cout << "Not enough tokens.  Total = " << T << "." << endl;
      } else {
        if ((n2 > n1 && b == 1) || (n1 > n2 && b == 0)) {
            T += t;
            cout << "Win " << t << "!  Total = " << T << "." << endl;
        } else {
            T -= t;
            cout << "Lose " << t << ".  Total = " << T << "." << endl;
        }
      }
    }
    return 0;
}