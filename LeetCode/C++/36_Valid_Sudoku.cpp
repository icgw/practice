/* Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 * 	1. Each row must contain the digits `1-9` without repetition.
 * 	2. Each column must contain the digits `1-9` without repetition.
 * 	3. Each of the 9 `3x3` sub-boxes of the grid must contain the digits `1-9`
 * 	   without repetion.
 */ 
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
	public:
		bool isValidSudoku(vector<vector<char>>& board){
			set<char> s;
			int s_size = 0;
			for (int i = 0; i < 9; ++i){
				for (int j = 0; j < 9; ++j){
					if (board[i][j] != '.'){
						s.insert(board[i][j]);
						++s_size;
					}
				}
				if (s.size() != s_size)
					return false;
				s.clear();
				s_size = 0;
				for (int j = 0; j < 9; ++j){
					if (board[j][i] != '.'){
						s.insert(board[j][i]);
						++s_size;
					}
				}
				if (s.size() != s_size)
					return false;
				s.clear();
				s_size = 0;
			}

			s.clear();
			s_size = 0;
			for (int i = 0; i < 9; i += 3){
				for (int j = 0; j < 9; j += 3){
					for (int ii = 0; ii < 3; ++ii){
						for (int jj = 0; jj < 3; ++jj){
							if (board[i + ii][j + jj] != '.'){
								s.insert(board[i + ii][j + jj]);
								++s_size;
							}
						}
					}
					if (s.size() != s_size)
						return false;
					s.clear();
					s_size = 0;
				}
			}

			return true;
		}

};
