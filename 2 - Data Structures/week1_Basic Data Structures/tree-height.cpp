#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)
///////////////////////////////////////
typedef long long ll;
typedef unsigned long long ull;
///////////////////////////////////////
const double EPS = (1e-12);
const double PI = acos(-1);
///////////////////////////////////////
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
///////////////////////////////////////

class Node;

class Node {
public:
	int key;
	Node *parent;
	std::vector<Node *> children;
	Node() {
		this->parent = NULL;
	}
	void setParent(Node *theParent) {
		parent = theParent;
		parent->children.push_back(this);
	}
};
int main_with_large_stack_space() {

	int n;
	std::cin >> n;
	int root = -1;
	std::vector<Node> nodes;
	nodes.resize(n);
	for (int child_index = 0; child_index < n; child_index++) {
		int parent_index;
		std::cin >> parent_index;

		if (parent_index >= 0)
			nodes[child_index].setParent(&nodes[parent_index]);
		else
			root = child_index;
		nodes[child_index].key = child_index;
	}
	int height = 0;
	//solution
	queue<int> q;
	q.push(root);
	while (q.size()) {
		height++;
		int sz = q.size();
		while (sz--) {
			root = q.front();
			q.pop();
			auto child = nodes[root].children;
			for (auto it : child) {
				q.push(it->key);
			}
		}
	}
	cout << height << endl;

//	// Replace this code with a faster implementation
//	int maxHeight = 0;
//	for (int leaf_index = 0; leaf_index < n; leaf_index++) {
//		int height = 0;
//		for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent) {
//			height++;
//			cout << v->key << " ";
//		}
//		cout << endl;
//
//		maxHeight = std::max(maxHeight, height);
//	}
//	std::cout << maxHeight << std::endl;
	return 0;
}
int main() {


	ios_base::sync_with_stdio(0);

	return main_with_large_stack_space();
}
