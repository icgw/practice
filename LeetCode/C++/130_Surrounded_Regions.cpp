/* Given a 2D board containing `X' and `O' (the letter O), capture all regions 
 * surrounded by `X'.
 * A region is captured by flipping all `0's into `X's in that surrounded region.
 * 
 * Example:
 * 	X X X X
 * 	X O O X
 * 	X X O X
 * 	X O X X
 *
 * After running your function, the board should be:
 *  X X X X
 *  X X X X
 *  X X X X
 *  X O X X
 */ 
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
	public:
		static void solve(vector<vector<char>>& board){
			stack<int> stkX, stkY;
			int n = board.size();
			if (n < 1) return ;
			int m = board[0].size();
			for (int i = 0; i < m; ++i){
				if (board[0][i] == 'O'){
					stkX.push(0); stkY.push(i);
					board[0][i] = '#';
					dfs(stkX, n - 1, stkY, m - 1, board);
				}
				if (board[n - 1][i] == 'O'){
					stkX.push(n - 1); stkY.push(i);
					board[n - 1][i] = '#';
					dfs(stkX, n - 1, stkY, m - 1, board);
				}
			}
			for (int i = 0; i < n; ++i){
				if (board[i][0] == 'O'){
					stkX.push(i); stkY.push(0);
					board[i][0] = '#';
					dfs(stkX, n - 1, stkY, m - 1, board);
				}
				if (board[i][m - 1] == 'O'){
					stkX.push(i); stkY.push(m - 1);
					board[i][m - 1] = '#';
					dfs(stkX, n - 1, stkY, m - 1, board);
				}
			}
			for (int i = 0; i < n; ++i){
				for (int j = 0; j < m; ++j){
					if (board[i][j] == '#'){
						board[i][j] = 'O';
					}
					else if (board[i][j] == 'O'){
						board[i][j] = 'X';
					}
				}
			}
		}

		static void dfs(stack<int>& stkX, int xn, 
				stack<int>& stkY, int yn,
				vector<vector<char>>& board){
			int x, y;
			while (!stkX.empty()){
				x = stkX.top(); stkX.pop();
				y = stkY.top(); stkY.pop();
				if (y > 0 && board[x][y - 1] == 'O'){
					stkX.push(x); stkY.push(y - 1);
					board[x][y - 1] = '#';
				}
				if (x > 0 && board[x - 1][y] == 'O'){
					stkX.push(x - 1); stkY.push(y);
					board[x - 1][y] = '#';
				}
				if (y < yn && board[x][y + 1] == 'O'){
					stkX.push(x); stkY.push(y + 1);
					board[x][y + 1] = '#';
				}
				if (x < xn && board[x + 1][y] == 'O'){
					stkX.push(x + 1); stkY.push(y);
					board[x + 1][y] = '#';
				}
			}
		}
};

int main(int argc, char* argv[]){
	vector<vector<char>> board(4, vector<char>(4, 'X'));
	board[1][1] = 'O'; board[1][2] = 'O';
	board[2][2] = 'O';
	board[3][1] = 'O';
	Solution::solve(board);
	for (auto& x : board){
		for (auto& y : x){
			cout << y << " ";
		}
		cout << endl;
	}

	return 0;
}
