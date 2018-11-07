/* Design a stack that supports push, pop, top and retrieving the minimum 
 * element in constant time.
 *
 * 	+ push(x)  -- Push element x onto stack.
 * 	+ pop()    -- Removes the element on top of the stack.
 * 	+ top()    -- Get the top element.
 * 	+ getMin() -- Retrieve the minimum element in the stack.
 */
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
	public:
		MinStack() { }

		void push(int x){
			stk.push(x);
			if (mtk.empty() || x <= mtk.top()) mtk.push(x);
		}

		void pop(){
			if (stk.top() == mtk.top()) mtk.pop();
			stk.pop();
		}

		int top(){
			return stk.top();
		}

		int getMin(){
			return mtk.top();
		}
	private:
		stack<int> stk, mtk;
};

int main(int argc, char *argv[]){
	MinStack minStk;
	minStk.push(-2);
	minStk.push(0);
	minStk.push(-3);
	cout << minStk.getMin() << endl;
	minStk.pop();
	minStk.top();
	cout << minStk.getMin() << endl;
	return 0;
}
