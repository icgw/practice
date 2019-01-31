#include <iostream>
#include "solution.hpp"

void run_example() {
    /* Example 1 */
    NestedInteger l1(1), l2(1), l3(2), l4(1), l5(1);
    vector<NestedInteger> lst1 { l1, l2 }, lst2 { l4, l5 };
    NestedInteger l12(lst1), l45(lst2);
    vector<NestedInteger> nestedList1 { l12, l3, l45 };

    NestedIterator i(nestedList1);
    while (i.hasNext()) std::cout << i.next() << " ";
    std::cout << "\n";

    /* Example 2 */
    NestedInteger l2_1(1), l2_2(4), l2_3(6);
    vector<NestedInteger> v2_3 { l2_3 };
    NestedInteger lst2_3(v2_3);
    vector<NestedInteger> lst2_2 { l2_2, lst2_3 };
    NestedInteger l2_23(lst2_2);
    vector<NestedInteger> nestedList2 { l2_1, l2_23 };

    NestedIterator i2(nestedList2);
    while (i2.hasNext()) std::cout << i2.next() << " ";
    std::cout << "\n";
}
