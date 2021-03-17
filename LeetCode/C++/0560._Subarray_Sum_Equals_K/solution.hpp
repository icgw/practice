#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
public:
  int subarraySum(vector<int>& nums, int k){
    int cum = 0, sz = nums.size(), cnt = 0;
    unordered_map<int, int> m{{0, 1}};
    for (int i = 0; i < sz; ++i){
      cum += nums[i];
      cnt += m[cum - k];
      ++m[cum];
    }
    return cnt;
  }
};
