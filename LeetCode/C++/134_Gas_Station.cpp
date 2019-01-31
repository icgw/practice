/* There are N gas stations along a circular route, where the amount of gas at 
 * station i is `gas[i]'.
 *
 * You have a car with an unlimited gas tank and it costs `cost[i]' of gas to 
 * travel from station i to its next station (i + 1). You begin the journey
 * with an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the circuit
 * once in the clockwise direction, otherwise return -1.
 *
 * Note:
 * 	+ If there exists a solution, it is guaranteed to be unique.
 * 	+ Both input arrays are non-empty and have the same length.
 * 	+ Each element in the input arrays is a non-negative integer.
 *
 * Example:
 * 	Input:
 * 		gas  = [1, 2, 3, 4, 5]
 * 		cost = [3, 4, 5, 1, 2]
 *  Output: 3
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
			int n = gas.size();
			int k, res;

			for (int i = 0; i < n; ++i){
				if (cost[i] > gas[i]) continue;
				res = 0;
				for (int j = 0; j < n; ++j){
					k = (i + j) % n;
					res += (gas[k] - cost[k]);
					if (res < 0) break;
				}
				if (res >= 0) return i;
			}
			return -1;
		}

};

int main(int argc, char* argv[]){
	vector<int> gas1  {1, 2, 3, 4, 5};
	vector<int> cost1 {3, 4, 5, 1, 2};
	cout << Solution::canCompleteCircuit(gas1, cost1) << endl;

	vector<int> gas2  {2, 3, 4};
	vector<int> cost2 {3, 4, 3};
	cout << Solution::canCompleteCircuit(gas2, cost2) << endl;

	return 0;
}
