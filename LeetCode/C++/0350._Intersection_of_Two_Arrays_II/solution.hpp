#include <vector>
using std::vector;

class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            if (nums1.size() == 0 || nums2.size() == 0) return { };
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
            vector<int> ret;
            for (int i = 0, j = 0; i < nums1.size() && j < nums2.size(); ) {
                if (nums1[i] < nums2[j]) {
                    ++i;
                } else if (nums1[i] > nums2[j]) {
                    ++j;
                } else {
                    ret.push_back(nums1[i]);
                    ++i; ++j;
                }
            }
            return ret;
        }
};
