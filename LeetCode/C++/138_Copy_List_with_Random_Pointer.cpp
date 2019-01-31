/* A linked list is given such that each node contains an additional random 
 * pointer which could point to any node in the list or null.
 * 
 * Return a deep copy of the list.
 */ 
#include <iostream>
#include <unordered_map>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
	public:
		static RandomListNode *copyRandomList(RandomListNode *head){
			if (!head) return NULL;
			// Insert Copying Node.
			RandomListNode *curr = head, *tmp;
			while (curr){
				tmp = new RandomListNode(curr->label);
				tmp->next = curr->next;
				curr->next = tmp;
				curr = tmp->next;
			}

			// Copying Random Node.
			curr = head;
			while (curr){
				tmp = curr->next;
				if (curr->random) tmp->random = curr->random->next;
				curr = tmp->next;
			}

			// Decouple Two LinkList
			curr = head;
			RandomListNode *cp = curr->next;
			while (curr){
				tmp = curr->next;
				curr->next = tmp->next;
				if (curr->next) tmp->next = curr->next->next;
				curr = curr->next;
			}
			return cp;
		}
};
