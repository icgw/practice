/* Given an array `A' of integers, return `true' if and only if it is a valid 
 * mountain array.
 *
 * Recall that `A' is a mountain array if and only if:
 * 	+ A.length >= 3
 * 	+ There exists some `i' with `0 < i < A.length - 1' such that:
 * 	  + `A[0] < A[1] < ... < A[i - 1] < A[i]
 * 	  + `A[i] > A[i + 1] > ... > A[A.length - 1]'
 * 
 * Example:
 *   Input: [0, 3, 2, 1]
 *  Output: true
 *
 * Note:
 *  1. `0 <= A.length <= 10000'
 *  2. `0 <= A[i] <= 10000'
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static bool validMountainArray(vector<int>& A){
			int n = A.size() - 1, i = 0;
			while (i < n && A[i] < A[i + 1]) ++i;

			if (i == 0 || i == n) return false;

			while (i < n && A[i] > A[i + 1]) ++i;

			return i == n;
		}
};

int main(int argc, char *argv[]){
	vector<int> A {0, 3, 2, 1};
	cout << Solution::validMountainArray(A) << endl;
	return 0;
}
