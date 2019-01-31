/* Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "a/./b/../../c", => "/c"
 * path = "/a/../../b/../c//.//", => "/c"
 * path = "/a//b////c/d//././/..", => "/a/b/c"
 *
 * In a UNIX-style file system, a period ('.') refers to the current directory, 
 * so it can be ignored in a simplified path. Additionally, a double period 
 * ("..") moves up a directory, so it cancels out whatever the last directory 
 * was.
 *
 * Corner Cases:
 *  + Did you consider the case where path = "/../" ?
 *    In this case, you should return "/".
 *  + Another corner case is the path might contain multiple slashes '/' 
 *    together, such as "/home//foo/".
 *    In this case, you should ignore redundant slashes and return "/home/foo".
 */ 
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
	public:
		static string simplifyPath(string path){
			stack<string> path_stack;
			int n = path.size();
			int i = 0, j;
			string tmp;
			while (i < n){
				while (i < n && path[i] == '/'){
					++i;
				}

				j = i;
				while (j < n && path[j] != '/'){
					++j;
				}
				tmp = path.substr(i, j - i);

				i = j;

				if (tmp.compare(".") == 0)
					continue;
				else if (!path_stack.empty() && tmp.compare("..") == 0)
					path_stack.pop();
				else if (tmp.compare("..") != 0)
					path_stack.push(tmp);
			}
			vector<string> out;
			while (!path_stack.empty()){
				out.push_back(path_stack.top());
				path_stack.pop();
			}
			string ans;
			for (int k = out.size() - 1; k >= 0; --k){
				if (out[k].empty())
					continue;
				ans.push_back('/');
				ans.append(out[k]);
			}

			if (ans.empty()){
				return "/";
			}

			return ans;
		}
};

int main(int argc, char* args[]){
	string path = "/a//b////c/d//././/..";
	cout << Solution::simplifyPath(path) << endl;

	string path2 = "/../";
	cout << Solution::simplifyPath(path2) << endl;

	string path3 = "/a/../../b/../c//.//";
	cout << Solution::simplifyPath(path3) << endl;

	string path4 = "/home//foo/";
	cout << Solution::simplifyPath(path4) << endl;

	string path5 = "/home/";
	cout << Solution::simplifyPath(path5) << endl;

	return 0;
}
