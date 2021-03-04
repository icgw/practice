/*
 * solution.h
 * Copyright (C) 2021 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the Apache license.
 */

#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <unordered_map>
#include <vector>
#include <string>
using std::unordered_map;
using std::string;
using std::vector;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        static unordered_map<string, int> m { { "type", 0 }, { "color", 1 }, { "name", 2 } };
        int idx = m[ruleKey];
        int ans = 0;
        for (auto& item : items) {
            if (item[idx] == ruleValue) {
                ++ans;
            }
        }
        return ans;
    }
};

#endif /* !_SOLUTION_H_ */

