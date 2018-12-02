#include <iostream>
#include "solution.h"

void run_example(){
	Solution s;
	vector<int> bar {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	std::cout << s.trap(bar) << std::endl;
}
