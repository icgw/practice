#include <vector>
using std::vector;
using std::swap;
using std::nth_element;

class Solution {
    public:
        void wiggleSort(vector<int>& nums) {
            int n = nums.size();
            nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
            int mid = nums[nums.size() / 2];
            int i = 0, j = 0, k = n - 1;

#define A(i) nums[(1 + 2 * (i)) % (n | 1)]
            while (j <= k) {
                if (A(j) > mid)
                    swap(A(j++), A(i++));
                else if (A(j) < mid)
                    swap(A(j), A(k--));
                else
                    ++j;
            }
#undef A
        }
};
