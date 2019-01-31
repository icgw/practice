/* Given a collection of intervals, merge all overlapping intervals.
 *
 * Example:
 * 	Input: [[1, 3], [2, 6], [8, 10], [15, 18]]
 * 	Output: [[1, 6], [8, 10], [15, 18]]
 */ 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
	public:
		static bool compareInterval(Interval x, Interval y){
			return (x.start < y.start);
		}

		static vector<Interval> merge(vector<Interval>& intervals){
			sort(intervals.begin(), intervals.end(), compareInterval);
			vector<Interval> ans;

			if (intervals.size() == 0){
				return ans;
			}

			ans.push_back(intervals[0]);
			Interval tmp;
			for (int i = 1; i < intervals.size(); ++i){
				Interval add = ans.back();
				if (add.end >= intervals[i].start){
					ans.pop_back();
					add.start = (add.start < intervals[i].start) ? 
						add.start : intervals[i].start;
					add.end = (add.end < intervals[i].end) ?
						intervals[i].end : add.end;
					ans.push_back(add);
				} else {
					ans.push_back(intervals[i]);
				}
			}
			return ans;
		}
};

int main(int argc, char* args[]){
	Interval a(1, 4), b(4, 5);
	vector<Interval> aa;
	aa.push_back(a);
	aa.push_back(b);

	vector<Interval> ans = Solution::merge(aa);
	for (auto& x : ans){
		cout << x.start << ", " << x.end << endl;
	}
	cout << endl;

	Interval c(1, 4), d(0, 2), e(3, 5);
	vector<Interval> bb;
	bb.push_back(c);
	bb.push_back(d);
	bb.push_back(e);

	vector<Interval> b_ans = Solution::merge(bb);
	for (auto& x : b_ans){
		cout << x.start << ", " << x.end << endl;
	}

	return 0;
}
