/* Implement a trie with `insert', `search', and `startsWith' methods.
 * 
 * Example:
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 *
 * Note:
 *  + You may assume that all inputs are consist of lowercase letters a-z.
 *  + All inputs are guaranteed to be non-empty strings.
 */
struct TrieNode {
	TrieNode *child[26];
	bool isWord;
	TrieNode() : isWord(false) {
		for (auto& n : child) n = NULL;
	}
};

class Trie {
	private:
		TrieNode *root;
	public:
	    /** Initialize your data structure here. */
	    Trie() {
			root = new TrieNode();
	    }
	    
	    /** Inserts a word into the trie. */
	    void insert(string word) {
			TrieNode *ptr = root;
			int i;
			for (auto& ch : word){
				//ptr->child[ch - 'a'] = new TrieNode(); // Wrong!!!
				i = ch - 'a';
				if (!ptr->child[i]) ptr->child[i] = new TrieNode();
				ptr = ptr->child[i];
			}
			ptr->isWord = true;
	    }
	    
	    /** Returns if the word is in the trie. */
	    bool search(string word) {
			TrieNode *ptr = root;
			int i;
			for (auto& ch : word){
				i = ch - 'a';
				if (!ptr->child[i]) return false;
				ptr = ptr->child[i];
			}
			return ptr->isWord;
	    }
	    
	    /** Returns if there is any word in the trie that starts with the given prefix. */
	    bool startsWith(string prefix) {
			TrieNode *ptr = root;
			int i;
			for (auto& ch : prefix){
				i = ch - 'a';
				if (!ptr->child[i]) return false;
				ptr = ptr->child[i];
			}
			return true;
	    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
