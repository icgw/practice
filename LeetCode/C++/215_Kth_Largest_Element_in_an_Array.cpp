/* Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 *
 * Example 1:
 *   Input: [3, 2, 1, 5, 6, 4] and k = 2
 *  Output: 5
 *
 * Example 2:
 *   Input: [3, 2, 3, 1, 2, 4, 5, 5, 6] and k = 4
 *  Output: 4
 *
 * Note:
 *  You may assume k is always valid, 1 <= k <= array's length.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int findKthLargest(vector<int>& nums, int k){
			int left = 0, right = nums.size() - 1;
			int j;
			while (true){
				j = partition(nums, left, right);
				if (j == k - 1) break;
				if (j < k - 1) left = j + 1; else right = j - 1; // Care!!!
			}
			return nums[j];
		}

		static int partition(vector<int>& nums, int left, int right){ 
			// partify it then it has [high -> low].
			int pivot = nums[left], lo = left + 1, hi = right;
			while (lo <= hi){ // Care!!!
				if (nums[lo] <= pivot && nums[hi] > pivot)
					swap(nums[lo], nums[hi]);
				if (nums[lo] > pivot) ++lo;
				if (nums[hi] <= pivot) --hi;
			}
			swap(nums[left], nums[hi]);
			return hi;
		}

		/* static int findKthLargest(vector<int>& nums, int k){
			int n = nums.size() - 1, j;
			int i = partitionH2L(nums, 0, n);
			while (i != k){
				while (i < k) i = partitionH2L(nums, i, n);
				if (i == k) return nums[i - 1];
				while (i > k) i = partitionH2L(nums, 0, i);
			}
			return nums[k - 1];
		}

		static int partitionH2L(vector<int>& nums, int s, int e){
			if (s >= e) return s + 1;
			int lo = s + 1, hi = e;
			int p = nums[s];
			while (lo < hi){
				while (lo < e && nums[lo] > p) ++lo;
				while (hi > s && nums[hi] <= p) --hi;
				if (lo < hi) swap(nums[lo], nums[hi]);
			}
			swap(nums[s], nums[hi]);
			return hi + 1;
		} */
};

int main(int argc, char *argv[]){
	vector<int> nums {3, 2, 3, 1, 2, 4, 5, 5, 6};
	int k = 4;
	cout << Solution::findKthLargest(nums, k) << endl;
	return 0;
}
