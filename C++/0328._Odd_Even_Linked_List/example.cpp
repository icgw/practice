#include <iostream>
#include "solution.hpp"

void run_example() {
    Solution s;
    ListNode *lst1 = s.oddEvenList(stringToListNode("[1, 2, 3, 4, 5]"));
    prettyPrintLinkedList(lst1);

    ListNode *lst2 = s.oddEvenList(stringToListNode("[2, 1, 3, 5, 6, 4, 7]"));
    prettyPrintLinkedList(lst2);
}
