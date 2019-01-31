/* Given a string `S' that only contains ``I'' (increase) or ``D'' (decrease),
 * let `N = S.length'.
 *
 * Return any permutation `A' of `[0, 1, ..., N]' such that for all
 * `i = 0, ..., N - 1':
 *   + If S[i] == ``I'', then `A[i] < A[i + 1]'
 *   + If S[i] == ``D'', then `A[i] > A[i + 1]'
 */ 



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	static vector<int> diStringMatch(string S){
        int lo = 0, hi = S.size();
        int n = hi;
        vector<int> ans;
        for (int i = 0; i < n; ++i){
            if (S[i] == 'I'){
                ans.push_back(lo);
                ++lo;
            } else {
                ans.push_back(hi);
                --hi;
            }
        }
        ans.push_back(lo);
        return ans;
	}

    /* static vector<int> diStringMatch(string S) {
        int sz = S.size();
        vector<bool> added(sz + 1, false);
        vector<int> ans;
		for (int i = 0; i <  sz + 1; ++i){
			added[i] = true;
			ans.push_back(i);
			doit(ans, S, added, 0, sz + 1);
			if (ans.size() == sz + 1) return ans;
			ans.pop_back();
			added[i] = false;
		}
        return ans;
    }
    
    static void doit(vector<int>& ans, string& S, vector<bool>& added, int pos, int N){
        if (S.size() == pos){
			for (int i = 0; i < N; ++i){
				if (added[i]) continue;
				if (S[pos - 1] == 'I' && ans.back() < i){
					ans.push_back(i);
					added[i] = true;
				}
				if (S[pos - 1] == 'D' && ans.back() > i){
					ans.push_back(i);
					added[i] = true;
				}
			}
			return ;
		}

        if (S[pos] == 'I'){
            for (int i = 0; i < N; ++i){
                if (!added[i] && i > ans.back()){
                    ans.push_back(i);
                    added[i] = true;
                    doit(ans, S, added, pos + 1, N);
                    if (ans.size() == N) return ;
                    ans.pop_back();
                    added[i] = false;
                }
            }
        }
        
        if (S[pos] == 'D'){
            for (int i = 0; i < N; ++i){
                if (!added[i] && i < ans.back()){
                    ans.push_back(i);
					added[i] = true;
                    doit(ans, S, added, pos + 1, N);
                    if (ans.size() == N) return ;
                    ans.pop_back();
                    added[i] = false;
                }
            }
        }
    } */
};

int main(int argc, char *argv[]){
	string S = "IDID";
	vector<int> ans = Solution::diStringMatch(S);
	for (auto& x : ans){
		cout << x << endl;
	}
	return 0;
}
