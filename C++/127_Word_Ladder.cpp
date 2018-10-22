/* Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 	1. Only one letter can be changed at a time.
 * 	2. Each transformed word must exist in the word list. Note that beginWord
 * 	   is not a transformed word.
 * Note:
 * 	+ Return 0 if there is no such transformation sequence.
 * 	+ All words have the same length.
 * 	+ All words contain only lowercase alphabetic characters.
 * 	+ You may assume no duplicates in the word list.
 * 	+ You may assume beginWord and endWord are non-empty and are not the same.
 */ 
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
	public:
		static int ladderLength(string beginWord, string endWord,
				vector<string>& wordList){
			unordered_set<string> wdLst(wordList.begin(), wordList.end());
			queue<string> q;
			q.push(beginWord);

			string curWord, newWord;
			int n, lad = 1;
			while (!q.empty()){
				for (int s = q.size(); s > 0; --s){
					curWord = q.front();
					if (curWord == endWord) return lad;
					q.pop();
					n = curWord.size();
					for (int i = 0; i < n; ++i){
						for (char ch = 'a'; ch <= 'z'; ++ch){
							newWord = curWord;
							newWord[i] = ch;
							if (wdLst.count(newWord) && newWord != curWord){
								q.push(newWord);
								wdLst.erase(newWord);
							}
						}
					}
				}
				++lad;
			}

			return 0;
		}
};

int main(int argc, char* argv[]){
	string beginWord = "hit", endWord = "cog";
	//vector<string> wordList{{"hot", "dot", "dog", "lot", "log", "cog"}};
	vector<string> wordList{{"hot", "dot", "dog", "lot", "log"}};
	cout << Solution::ladderLength(beginWord, endWord, wordList) << endl;
	return 0;
}
