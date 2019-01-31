using std::string;

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if (s.length() != t.length()) return false;
            int alpha[26] = { 0 };
            for (int i = 0; i < s.length(); ++i) {
                alpha[s[i] - 'a']++;
                alpha[t[i] - 'a']--;
            }
            for (auto c : alpha) if (c != 0) return false;
            return true;
        }

        /******************************************
        bool isAnagram(string s, string t) {
            if (s.size() != t.size()) return false;
            int alpha[26] = { 0 };
            int count = 0;
            for (auto c : s) {
                if (alpha[c - 'a'] == 0) {
                    count++;
                }
                alpha[c - 'a']++;
            }

            for (auto c : t) {
                alpha[c - 'a']--;
                if (alpha[c - 'a'] == 0) count--;
            }

            return count == 0;
        }
         ******************************************/
};
