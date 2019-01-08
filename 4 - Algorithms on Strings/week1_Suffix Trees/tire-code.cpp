class trie {

public:

	trie* child[26];
	bool isLeaf;
	trie() {
		memset(child, 0, sizeof(child));
		isLeaf = false;
	}
	void insert(char*str) {
		if (*str == '\0') {
			isLeaf = true;
		} else {
			int cur = *str - 'a';
			if (child[cur] == 0)
				child[cur] = new trie();
			child[cur]->insert(str + 1);
		}
	}
	bool worldExist(char* str) {
		if (*str == '\0')
			return isLeaf;
		int cur = *str - 'a';
		if (child[cur] == 0)
			return false;
		return child[cur]->worldExist(str + 1);
	}
	bool prefixExist(char* str) {
		if (*str == '\0')
			return true;
		int cur = *str - 'a';
		if (child[cur] == 0)
			return false;
		return child[cur]->worldExist(str + 1);
	}
};