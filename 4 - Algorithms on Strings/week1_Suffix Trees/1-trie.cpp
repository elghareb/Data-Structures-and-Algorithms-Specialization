#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
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
};

string prt(int i, int j, char c) {
	stringstream ss;
	ss << i << "->" << j << ":" << c << "\n";
	return ss.str();
}

int main() {

	Trie root;
	int n;
	cin >> n;
	string s;
	while (n--) {
		cin >> s;
		root.insert(s);
	}

	int c = 0;
	queue<pair<Trie, int>> q;
	q.push( { root, c });

	while (q.size()) {
		auto t = q.front();
		Trie parentTrie = t.first;
		q.pop();
		//parentTrie -> child = map (char,*Trie)

		for (auto it : parentTrie.child) {
			c++;
			q.push( { *parentTrie.child[it.first], c });
			cout << prt(t.second, c, it.first);
		}
	}

	return 0;
}

