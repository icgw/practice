#include "../data_structures.hpp"

class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
            ListNode *odd, *even;
            odd = head;
            if (!head || !head->next) return head;
            even = head->next;
            ListNode *ttmp = odd, *htmp = even;
            while (odd || even) {
                if (odd && odd->next) {
                    ttmp = odd;
                    odd->next = odd->next->next;
                }
                if (even && even->next) {
                    even->next = even->next->next;
                }
                if (odd) {
                    ttmp = odd;
                    odd = odd->next;
                }
                if (even) even = even->next;
            }
            ttmp->next = htmp;
            return head;
        }
};
