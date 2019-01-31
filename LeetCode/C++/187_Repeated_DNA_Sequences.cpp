/* All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T,
 * for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to 
 * identify repeated sequences within the DNA.
 *
 * Write a function to find all the 10-letter-long sequences (substrings) that
 * occur more than once in a DNA molecule.
 *
 * Example:
 *   Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 *  Output: ["AAAAACCCCC", "CCCCCAAAAA"]
 */
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
	public:
		static vector<string> findRepeatedDnaSequences(string s){ // Not Good...
			unordered_set<string> st, res;
			vector<string> ans;
			int n = s.size() - 9;
			string str;
			for (int i = 0; i < n; ++i){
				str = s.substr(i, 10);
				if (st.count(str)) res.insert(str);
				st.insert(str);
			}
			for (auto& x : res){
				ans.push_back(x);
			}
			return ans;
		}
};

int main(int argc, char *argv[]){
	//cout << bitset<8>('A') << endl; // print 01000001, (..001)
	//cout << bitset<8>('C') << endl; // print 01000011, (..011)
	//cout << bitset<8>('G') << endl; // print 01000111, (..111)
	//cout << bitset<8>('T') << endl; // print 01010100, (..100)
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";	
	vector<string> ans = Solution::findRepeatedDnaSequences(s);
	for (auto& x : ans) cout << x << endl;
	return 0;
}
