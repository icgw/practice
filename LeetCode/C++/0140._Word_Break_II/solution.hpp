#include <vector>
using std::vector;
using std::string;
using std::function;

#include <unordered_set>
using std::unordered_set;
#include <unordered_map>
using std::unordered_map;

class Solution {
    public:
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> wd(wordDict.begin(), wordDict.end());
            unordered_map<int, vector<string>> memo {{ s.size(), {""}}};
            function<vector<string>(int)> sentences = [&](int i) {
                if (!memo.count(i))
                    for (int j = i + 1; j <= s.size(); ++j)
                        if (wd.count(s.substr(i, j - i)))
                            for (string tail : sentences(j))
                                memo[i].push_back(s.substr(i, j - i) + (tail == "" ? "" : " " + tail));
                return memo[i];
            };
            return sentences(0);
        }
};
