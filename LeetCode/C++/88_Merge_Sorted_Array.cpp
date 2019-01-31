/* Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as 
 * one sorted array.
 *
 * Note:
 * 	+ The number of elements initialized in nums1 and nums2 are m and n 
 * 	  respectively.
 * 	+ You may assume that nnums1 has enough space (size that is greater or equal
 * 	  to m + n) to hold additional elements from nums2.
 */ 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
			if (n == 0) return;
			int pos = nums1.size() - 1;
			int i = m - 1, j = n - 1;
			while (i >= 0 && j >= 0){
				if (nums1[i] > nums2[j]){
					nums1[pos] = nums1[i];
					--i;
				} else {
					nums1[pos] = nums2[j];
					--j;
				}
				--pos;
			}

			while (j >= 0){
				nums1[pos] = nums2[j];
				--j; --pos;
			}
		}
};

int main(int argc, char* args[]){
	vector<int> nums1(6, 0);
	nums1[0] = 1; nums1[1] = 2; nums1[2] = 3;
	int m = 3;
	vector<int> nums2(3, 0);
	nums2[0] = 2; nums2[1] = 5; nums2[2] = 6;
	int n = 3;

	Solution::merge(nums1, m, nums2, n);
	for (int i = 0; i < nums1.size(); ++i){
		cout << nums1[i] << " ";
	}
	cout << endl;

	return 0;
}
