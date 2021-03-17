#include <vector>
using std::vector;

class Solution {
public:
  int trap(vector<int>& height){
    int lo = 0, hi = height.size() - 1;
    int level = 0, lower = 0, water = 0;
    while (lo < hi){
      lower = height[height[lo] < height[hi] ? lo++ : hi--];
      level = std::max(lower, level);
      water += (level - lower);
    }
    return water;
  }
};
