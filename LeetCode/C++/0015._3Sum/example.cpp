/* Given an array `nums` of n integers, are there elements a, b, c in `nums`
 * such that a + b + c = 0? Find all unique triplets in the array which gives
 * the sum of zero.
 *
 * Note:
 * The solution set must not contain duplicate triplets.
 */ 
#include "solution.h"
#include <iostream>

using namespace std;

void run_example() {
  int a[] = {-1, 0, 1, 2, -1, -4};
  int b[] = {0, 0, 0};
  int c[] = {-2, 0, 1, 1, 2};
  vector<int> aa(a, a + 6);
  vector<int> bb(b, b + 3);
  vector<int> cc(c, c + 5);

  Solution sln;

  vector<vector<int> > ans = sln.threeSum(aa);
  for (auto& x : ans){
    cout << x[0] << " " << x[1] << " " << x[2] << endl;
  }

  cout << endl;
  vector<vector<int> > b_ans = sln.threeSum(bb);
  for (auto& x : b_ans){
    cout << x[0] << " " << x[1] << " " << x[2] << endl;
  }

  cout << endl;
  vector<vector<int> > c_ans = sln.threeSum(cc);
  for (auto& x : c_ans){
    cout << x[0] << " " << x[1] << " " << x[2] << endl;
  }
}
