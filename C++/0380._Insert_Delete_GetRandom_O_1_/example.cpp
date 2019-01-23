#include <iostream>
#include "solution.hpp"

void run_example() {
    RandomizedSet randomSet;

    std::cout << randomSet.insert(1) << std::endl;
    std::cout << randomSet.remove(2) << std::endl;
    std::cout << randomSet.insert(2) << std::endl;
    std::cout << randomSet.getRandom() << std::endl;
    std::cout << randomSet.remove(1) << std::endl;
    std::cout << randomSet.insert(2) << std::endl;
    std::cout << randomSet.getRandom() << std::endl;
}
