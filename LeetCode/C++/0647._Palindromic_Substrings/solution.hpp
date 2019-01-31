using std::string;

class Solution {
    private:
        void expand(int &count, string s, int lo, int hi){
            while (lo >= 0 && hi < s.length() && s[lo] == s[hi]){
                --lo;
                ++hi;
                ++count;
            }
        }

    public:
        int countSubstrings(string s) {
            int sz = s.size();
            int count = 0;
            for (int i = 0; i < sz; ++i){
                expand(count, s, i, i);
                expand(count, s, i, i + 1);
            }
            return count;
        }
};
