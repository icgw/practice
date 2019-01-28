using std::string;
class Solution {
    public:
        bool isMatch(string s, string p) {
            const char *c_s = s.c_str(), *c_p = p.c_str();
            const char *star = nullptr, *ss = c_s;
            while (*c_s) {
                if (*c_p == '?' || *c_s == *c_p) { c_p++; c_s++; continue; }
                if (*c_p == '*') { star = c_p++; ss = c_s; continue; }
                if (star) { c_p = star + 1; c_s = ++ss; continue; }
                return false;
            }
            while (*c_p == '*') c_p++;
            return !*c_p;
        }
};
