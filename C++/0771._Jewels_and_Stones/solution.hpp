using std::string;

class Solution {
    public:
        int numJewelsInStones(string J, string S){
            if (J.empty() || S.empty()) return 0;
            int count = 0;
            for (auto& ch : S) if (J.find(ch) != string::npos) ++count;
            return count;
        }
};
