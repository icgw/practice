#include <vector>
using std::vector;
using std::min;
using std::max;

class Solution {
public:
  int numSquares(int n){
    static vector<int> result{0};
    int m = result.size();
    while (m <= n) {
      int cnt = INT_MAX;
      for (int i = 1; i * i <= m; ++i) {
        cnt = min(cnt, result[m - i * i] + 1);
      }
      result.push_back(cnt);
      ++m;
    }
    return result[n];
  }
};
