/* Given a set of points in the xy-plane, determine the minimum area of a 
 * rectangle formed from these points, with sides parallel to the x and y axes.
 * If there isn't any rectangle, return 0.
 *
 * Example:
 * 	 Input: [[1, 1], [1, 3], [3, 1], [3, 3], [4, 1], [4, 3]]
 * 	Output: 2
 *
 * Note:
 * 	1. 1 <= points.lenght <= 500
 * 	2. 0 <= points[i][0] <= 40000
 * 	3. 0 <= points[i][1] <= 40000
 * 	4. All points are distinct.
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
	public:
		static int minAreaRect(vector<vector<int>>& points){
			set<pair<int, int>> s;
			for (auto& p : points){
				s.insert({p[0], p[1]});
			}
			int res = INT_MAX;
			for (auto i = s.begin(); i != s.end(); ++i){
				for (auto j = next(i); j != s.end(); ++j){
					if (i->first == j->first || i->second == j->second)
						continue;
					if (s.count({i->first, j->second}) &&
							s.count({j->first, i->second})){
						res = min(res, abs((i->first - j->first) *
									(i->second - j->second)));
					}
				}
			}
			return res == INT_MAX ? 0 : res;
		}
};

int main(int argc, char *argv[]){
	vector<vector<int>> rect { {1, 1}, {1, 3}, {3, 1}, {3, 3}, {2, 2} };
	cout << Solution::minAreaRect(rect) << endl;
	return 0;
}
