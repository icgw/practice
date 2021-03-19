#include <iostream>
#include "solution.h"

void run_example() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << std::endl; // returns 1
    cache.put(3, 3);                        // evicts key 2
    std::cout << cache.get(2) << std::endl; // returns -1 (not found)
    cache.put(4, 4);                        // evicts key 1
    std::cout << cache.get(1) << std::endl; // returns -1 (not found)
    std::cout << cache.get(3) << std::endl; // return 3
    std::cout << cache.get(4) << std::endl; // return 4
}
