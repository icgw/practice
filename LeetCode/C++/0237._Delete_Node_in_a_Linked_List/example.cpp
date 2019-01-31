#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    ListNode *lst1 = stringToListNode("[4, 5, 1, 9]");
    ListNode *del1 = lst1->next;
    s.deleteNode(del1);
    prettyPrintLinkedList(lst1);

    ListNode *lst2 = stringToListNode("[4, 5, 1, 9]");
    ListNode *del2 = lst2->next->next;
    s.deleteNode(del2);
    prettyPrintLinkedList(lst2);
}
