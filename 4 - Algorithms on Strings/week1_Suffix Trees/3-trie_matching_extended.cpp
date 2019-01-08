#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define clr(a,v) memset(a,v,sizeof a)
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x) * (x))

///////////////////////////////////////
class Trie {
public:
	unordered_map<char, Trie*> child;
	bool isLeaf;
	Trie() {
		isLeaf = 0;
	}
	void insert(string word) {
		Trie *current = this;
		for (auto c : word) {
			Trie *node = current->child[c];
			if (!node) {
				node = new Trie();
				current->child[c] = node;
			}
			current = node;
		}
		current->isLeaf = 1;
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
		return current->isLeaf;
	}

};
int main() {

	string t;
	cin >> t;
	int n;
	cin >> n;

	Trie tri;

	string w;
	for (int i = 0; i < n; ++i) {
		cin >> w;
		tri.insert(w);
	}

	vector<int> ans;
	string tmp;
	for (int i = 0; i < SZ(t); ++i) {
		tmp = "";
		Trie *current = &tri;
		int j = i;
		while (true) {
			char c = t[j];
			if (current->child[c]) {
				current = current->child[c];
				if (current->isLeaf) {
					cout << i << " ";
					break;
				}
			} else {
				break;
			}
			j++;
		}
	}

	return 0;
}

