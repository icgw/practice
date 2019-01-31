/* There are a total of n courses you have to take, labeled from `0' to `n - 1'.
 *
 * Some courses may have prerequisites, for example to take course 0 you have to
 * first take course 1, which is expressed as a pair: `[0, 1]'
 *
 * Given the total number of courses and a list of prerequisite _pairs_, is it 
 * possible for you to finish all courses?
 *
 * Example 1:
 *
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 *              To take course 1 you should have finished course 0. 
 *              So it is possible.
 *
 * Example 2:
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 *              To take course 1 you should have finished course 0, and to take 
 *              course 0 you should also have finished course 1. 
 *              So it is impossible.
 *
 * Note:
 *  1. The input prerequisites is a graph represented by a list of edges, not 
 *     adjacency matrices. Read more about how a graph is represented.
 *  2. You may assume that there are no duplicate edges in the input prerequisites.
 */
#include <iostream>
#include <vector>
#include<queue>

using namespace std;

class Solution {
	public:
		static bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites){
			vector<vector<int>> graph(numCourses);
			vector<int> inDegree(numCourses, 0);
			for (auto& e : prerequisites){
				graph[e.second].push_back(e.first);
				++inDegree[e.first];
			}
			queue<int> q;
			for (int i = 0; i < numCourses; ++i){
				if (inDegree[i] == 0) q.push(i);
			}

			int counter = 0, u;
			while (!q.empty()){
				u = q.front();
				q.pop();
				++counter;
				for (auto& v : graph[u]){
					if (--inDegree[v] == 0) q.push(v);
				}
			}
			return counter == numCourses;
		}
};

int main(int argc, char *argv[]){
	int n = 2;
	vector<pair<int, int>> p {{1, 0}, {0, 1}};
	cout << Solution::canFinish(n, p) << endl;
	return 0;
}
