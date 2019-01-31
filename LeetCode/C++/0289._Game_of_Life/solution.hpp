#include <vector>
using std::vector;

class Solution {
    private:
        bool isValid(int x, int y, int m, int n) {
            return x >= 0 && x < m && y >= 0 && y < n;
        }

        bool check(vector<vector<int>>& board, int x, int y, int m, int n) {
            static constexpr int dx[8] = { 0,  0, 1, 1,  1, -1, -1, -1 };
            static constexpr int dy[8] = { 1, -1, 1, 0, -1,  1,  0, -1 };
            if (!isValid(x, y, m, n)) return false;
            int neighbors = 0;
            for (int i = 0; i < 8; ++i) {
                int curr_x = x + dx[i], curr_y = y + dy[i];
                if (!isValid(curr_x, curr_y, m, n)) continue;
                if (board[curr_x][curr_y] == 1) neighbors++;
            }
            if (((neighbors < 2 || neighbors > 3) && board[x][y] == 1) || (neighbors == 3 && board[x][y] == 0)) return true;
            return false;
        }
    public:
        void gameOfLife(vector<vector<int>>& board) {
            int m = board.size();
            if (m <= 0) return ;
            int n = board[0].size();
            vector<vector<bool>> isChange(m, vector<bool>(n, false));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    isChange[i][j] = check(board, i, j, m, n);
                }
            }

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (isChange[i][j]) board[i][j] = (board[i][j] + 1) % 2;
                }
            }
        }
};
