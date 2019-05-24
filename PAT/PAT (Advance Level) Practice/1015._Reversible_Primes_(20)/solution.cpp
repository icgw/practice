#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    if (num < 4) return true;
    int r = sqrt(num);
    for (int i = 2; i <= r; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main()
{
    int N, D;
    while (cin >> N) {
        if (N < 0) break;
        cin >> D;
        if (!isPrime(N)) {
            cout << "No\n";    
        } else {
            vector<int> arr (32, 0);
            int i = 0, num = N;

            while (num > 0) {
                arr[i++] = num % D;
                num /= D;
            }

            int rev_num = 0, carry = 1;
            do {
                i--;
                rev_num += (arr[i] * carry);
                carry *= D;
            } while (i > 0);

            if (!isPrime(rev_num)) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        }
    }
    return 0;
}