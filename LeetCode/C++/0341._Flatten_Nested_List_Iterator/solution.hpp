#include <vector>
#include <stack>
using std::vector;
using std::stack;

class NestedInteger {
    public:
        NestedInteger(int i) :
            is_integer(true), integer(i), list(vector<NestedInteger>{}) {}
        NestedInteger(vector<NestedInteger> nestedList) :
            is_integer(false), integer(0), list(nestedList) {}
        NestedInteger(bool b, int i, vector<NestedInteger> v) :
            is_integer(b), integer(i), list(v) {}
        NestedInteger(bool b, int i) : 
            is_integer(b), integer(i), list(vector<NestedInteger>{}) {}

        bool isInteger() const;
        int getInteger() const;
        vector<NestedInteger> &getList();

    private:
        bool is_integer = false;
        int  integer = 0;
        vector<NestedInteger> list;
};

inline bool NestedInteger::isInteger() const { return is_integer; }

inline int NestedInteger::getInteger() const { return integer; }

inline vector<NestedInteger>& NestedInteger::getList() { return list; }

class NestedIterator {
    private:
        stack<vector<NestedInteger>::iterator> begins, ends;

    public:
        NestedIterator(vector<NestedInteger> &nestedList) {
            begins.push(nestedList.begin());
            ends.push(nestedList.end());
        }

        int next() {
            hasNext();
            return (begins.top()++)->getInteger();
        }

        bool hasNext() {
            while (!begins.empty()) {
                if (begins.top() == ends.top()) {
                    begins.pop();
                    ends.pop();
                } else {
                    if (begins.top()->isInteger()) {
                        return true;
                    } else {
                        auto &x = (begins.top()++)->getList();
                        begins.push(x.begin());
                        ends.push(x.end());
                    }
                }
            }
            return false;
        }
};
