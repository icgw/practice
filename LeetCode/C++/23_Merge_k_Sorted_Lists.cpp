/* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 * 
 * Example:
 * Input:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 */
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		static ListNode* mergeKLists(vector<ListNode*>& lists){
			ListNode* dummy = new ListNode(0);
			dfs(dummy, lists);
			return dummy->next;
		}

		static void dfs(ListNode *p, vector<ListNode*>& lists){
			if (!p) return ;
			ListNode **m = NULL;
			int minv = INT_MAX;
			for (auto& x : lists){
				if (x && x->val < minv){
					m = &x;
					minv = x->val;
				}
			}
			p->next = minv == INT_MAX ? NULL : *m;
			if (m && *m) *m = (*m)->next;
			dfs(p->next, lists);
		}
};

int main(int argc, char *argv[]){
	vector<ListNode*> lists {new ListNode(1), new ListNode(1), new ListNode(2)};
	lists[0]->next = new ListNode(4); lists[0]->next->next = new ListNode(5);
	lists[1]->next = new ListNode(3); lists[1]->next->next = new ListNode(4);
	lists[2]->next = new ListNode(6);
	ListNode* ans = Solution::mergeKLists(lists);
	while (ans){
		cout << ans->val << endl;
		ans = ans->next;
	}
	return 0;
}
