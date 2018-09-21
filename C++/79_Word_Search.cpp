/* Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, where
 * ``adjacent'' cells are those horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 */ 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		static bool exist(vector<vector<char>>& board, string word){
			int m = board.size();
			if (m < 1) return false;
			int n = board[0].size();
			if (n < 1) return false;
			if (word.size() < 1) return true;
			for (int i = 0; i < m; ++i){
				for (int j = 0; j < n; ++j){
					if (doit(board, word, i, j))
						return true;
				}
			}

			return false;
		}

		static bool doit(vector<vector<char>>& board, string subword, 
				int row, int col){
			if (subword.size() == 1){
				if (board[row][col] == subword[0])
					return true;
				else
					return false;
			}

			char curr = board[row][col];
			if (subword[0] == board[row][col]){
				board[row][col] = '0';
				if (row > 0){
					if (doit(board, subword.substr(1, subword.size() - 1),
								row - 1, col)){
						board[row][col] = curr;
						return true;
					}
				}
				if (row < board.size() - 1){
					if (doit(board, subword.substr(1, subword.size() - 1),
								row + 1, col)){
						board[row][col] = curr;
						return true;
					}
				}
				if (col > 0){
					if (doit(board, subword.substr(1, subword.size() - 1),
								row, col - 1)){
						board[row][col] = curr;
						return true;
					}
				}
				if (col < board[0].size() - 1){
					if (doit(board, subword.substr(1, subword.size() - 1),
								row, col + 1)){
						board[row][col] = curr;
						return true;
					}
				}
				board[row][col] = curr;
			}
			return false;
		}
};

int main(int argc, char* args[]){
	vector<vector<char>> board(3, vector<char>(4, '0'));
	board[0][0] = 'A'; board[0][1] = 'B'; board[0][2] = 'C'; board[0][3] = 'E';
	board[1][0] = 'S'; board[1][1] = 'F'; board[1][2] = 'C'; board[1][3] = 'S';
	board[2][0] = 'A'; board[2][1] = 'D'; board[2][2] = 'E'; board[2][3] = 'E';

	string word1 = "ABCCED";
	string word2 = "SEE";
	string word3 = "ABCB";

	cout << Solution::exist(board, word1) << endl;
	cout << Solution::exist(board, word2) << endl;
	cout << Solution::exist(board, word3) << endl;


	return 0;
}
