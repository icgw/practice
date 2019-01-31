using std::string;

class Solution {
    public:
        string decodeString(string s){
            int i = 0;
            return decodeString(s, s.length(), i);
        }
    private:
        string decodeString(string& s, const int len, int& i){
            string ret = "";
            while (i < len && s[i] != ']'){
                if (i < len && !isDigit(s[i])){
                    ret += s[i++];
                } else {
                    int n = 0;
                    while (i < len && isDigit(s[i])){
                        n = 10 * n + (s[i++] - '0');
                    }

                    ++i;
                    string tmp = decodeString(s, len, i);
                    ++i;

                    while (n-- > 0) ret += tmp;
                }
            }
            return ret;
        }

        bool isDigit(char ch){ return ch >= '0' && ch <= '9';}
};
