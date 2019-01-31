#include <vector>
#include <cmath>
using std::vector;

class Solution {
    public:
        int countPrimes(int n) {
            if (n <= 2) return 0;
            vector<bool> notPrime(n, false);
            int count = 1;
            int sqrtn = sqrt(n);
            for (int i = 3; i < n; i += 2) {
                if (!notPrime[i]) {
                    ++count;
                    if (i > sqrtn) continue; // avoid overflow of 'i * i'
                    for (int j = i * i; j < n; j += i) notPrime[j] = true;
                }
            }
            return count;
        }

        /************ Bad idea *******************
        int countPrimes(int n) {
            int count = n - 2;
            vector<int> nums(n, 1);
            for (int i = 2; i < n; ++i) {
                if (nums[i] == 0) continue;
                for (int j = 2; j * i < n; ++j) {
                    if (nums[j * i] == 1) {
                        count--;
                        nums[j * i] = 0;
                    }
                }
            }
            return count < 0 ? 0 : count;
        }
         *****************************************/
};
