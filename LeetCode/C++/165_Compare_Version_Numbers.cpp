/* Compare two version numbers version1 and version2.
 *
 * If vecsion1 > version2 return 1; if vecsion1 < version2 return -1; 
 * otherwise return 0.
 */
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
	public:
		static int compareVersion(string version1, string version2){
			istringstream v1(version1 + "."), v2(version2 + ".");
			int d1 = 0, d2 = 0;
			char dot;
			while (v1.good() || v2.good()){
				v1 >> d1 >> dot;
				v2 >> d2 >> dot;
				if (d1 > d2) return 1;
				else if (d1 < d2) return -1;
				d1 = d2 = 0;
			}
			return 0;
		}
};

int main(int argc, char *argv[]){
	string version1 = "7.5.2.4", version2 = "7.5.3";
	cout << Solution::compareVersion(version1, version2) << endl;
	return 0;
}
