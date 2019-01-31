/* There are two sorted arrays `nums1' and `nums2' of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity 
 * should be O(log (m + n)).
 *
 * You may assume `nums1' and `nums2' cannot be both empty.
 *
 * Example:
 *  nums1 = [1, 2]
 *  nums2 = [3, 4]
 *
 *  The median is (2 + 3) / 2 = 2.5
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static double findMedianSortedArrays(vector<int>& nums1, 
				vector<int>& nums2){ // Recursive
			int sz1 = nums1.size(), sz2 = nums2.size();
			int lm = (sz1 + sz2 + 1) / 2, rm = (sz1 + sz2 + 2) / 2;
			return (findKth(nums1, 0, nums2, 0, lm) + findKth(nums1, 0, nums2, 0, rm)) / 2;
		}

		static double findKth(vector<int>& nums1, int i1,
				vector<int>& nums2, int i2, int k){
			if (i1 >= nums1.size()) return nums2[i2 + k - 1];
			if (i2 >= nums2.size()) return nums1[i1 + k - 1];
			if (k == 1) return min(nums1[i1], nums2[i2]);
			int v1 = i1 + k / 2 - 1 < nums1.size() ?
				nums1[i1 + k / 2 - 1] : INT_MAX;
			int v2 = i2 + k / 2 - 1 < nums2.size() ? 
				nums2[i2 + k / 2 - 1] : INT_MAX;
			if (v1 < v2){
				return findKth(nums1, i1 + k / 2, nums2, i2, k - k / 2);
			} else {
				return findKth(nums1, i1, nums2, i2 + k / 2, k - k / 2);
			}
		}
};

int main(int argc, char *argv[]){
	vector<int> nums1 {1, 2}, nums2 {3, 4};
	cout << Solution::findMedianSortedArrays(nums1, nums2) << endl;
	return 0;
}
