/* Given a string `S', count the number of distinct, non-empty subsequences of
 * `S'.
 *
 * Since the result may be large, return the answer modulo 10^9 + 7.
 *
 * Note:
 * 	1. `S' contains only lowercase letters
 * 	2. 1 <= S.length <= 2000
 */
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
	public:
		static int distinctSubseqII(string S){
			int dp = 1, mod = 1e9 + 7, prev;
			unordered_map<char, int> m;
			for (auto ch : S){
				prev = dp;
				dp <<= 1;
				dp %= mod;
				if (m.find(ch) != m.end()){
					dp -= m[ch];
					dp %= mod;
				}
				m[ch] = prev % mod;
			}
			return (dp - 1 < 0) ? (dp - 1 + mod) : (dp - 1) % mod;
		}
};

int main(int argc, char *argv[]){
	string s = "zchmliaqdgvwncfatcfivphddpzjkgyygueikthqzyeeiebczqbqhdytkoawkehkbizdmcnilcjjlpoeoqqoqpswtqdpvszfaksn";
	cout << Solution::distinctSubseqII(s) << endl;
	return 0;
}

