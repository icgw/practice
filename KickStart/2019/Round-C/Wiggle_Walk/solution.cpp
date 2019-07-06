/*
 * solution.cpp
 * Copyright (C) 2019 Guowei Chen <icgw@outlook.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <vector>
using namespace std;

int GetDir(char ch) {
    switch (ch) {
        case 'N': return 0;
        case 'S': return 1;
        case 'E': return 2;
        case 'W': return 3;
    }
    return -1;
}

vector<int> rbtMove(vector<vector<bool>> &visited,
                    int r,
                    int c,
                    int d)
{
    static const vector<vector<int>> dirs {
        { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 }
    };

    do {
        visited[r][c] = true;
        r += dirs[d][0];
        c += dirs[d][1];
    } while (visited[r][c]);

    return { r, c };
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int N, R, C, SR, SC;
        cin >> N >> R >> C >> SR >> SC;

        vector<int> pos { SR, SC };
        vector<vector<bool>> visited (R + 1, vector<bool>(C + 1, false));

        char d;
        for (int k = 0; k < N; ++k) {
            cin >> d;
            pos = rbtMove(visited, pos[0], pos[1], GetDir(d));
        }

        cout << "Case #" << i << ": " << pos[0] << " " << pos[1] << "\n";
    }
    return 0;
}
