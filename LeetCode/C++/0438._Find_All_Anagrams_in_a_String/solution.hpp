#include <vector>
using std::vector;
using std::string;

class Solution {
    public:
        vector<int> findAnagrams(string s, string p){
            vector<int> sw(26, 0), pw(26, 0);
            int n = s.size(), sz = p.size();
            for (int i = 0; i < sz; ++i){
                ++sw[s[i] - 'a'];
                ++pw[p[i] - 'a'];
            }

            vector<int> ret;
            for (int i = sz; i < n; ++i){
                if (sw == pw) ret.push_back(i - sz);
                --sw[s[i - sz] - 'a'];
                ++sw[s[i] - 'a'];
            }

            if (sw == pw) ret.push_back(n - sz);
            return ret;
        }

    /**********************************************************
    public:
        vector<int> findAnagrams(string s, string p){
            int sz = p.size(), n = s.size();
            sort(p.begin(), p.end());
            if (n < sz) return {};
            string anagrams(s, 0, sz);
            vector<int> ret;
            for (int i = 0; i <= n - sz; ++i){
                if (isAnagrams(anagrams, p)) ret.push_back(i);
                anagrams[i % sz] = s[i + sz];
            }
            return ret;
        }
    private:
        bool isAnagrams(string ana, string s){
            sort(ana.begin(), ana.end());
            return ana == s;
        }
     ***********************************************************/
};
