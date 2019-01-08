class Trie {
public:
	unordered_map<char, Trie*> child;
	bool isLeaf;
	Trie() {
		isLeaf = false;
	}
	void insert(string word) {
		Trie * current = this;
		for (auto c : word) {
			Trie *node = current->child[c];
			if (!node) {
				node = new Trie();
				current->child[c] = node;
			}
			current = node;
		}
		current->isLeaf = true;
	}
	bool worldExist(string word) {
		Trie *current = this;
		for (auto c : word) {
			Trie *node = current->child[c];
			if (!node) {
				return false;
			}
			current = node;
		}
		return current->isLeaf;
	}
	bool prefixExist(string word) {
		Trie *current = this;
		for (auto c : word) {
			Trie *node = current->child[c];
			if (!node) {
				return false;
			}
			current = node;
		}
		return true;
	}

};