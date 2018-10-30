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

struct Node {
	int key;
	int left;
	int right;

	Node() :
			key(0), left(-1), right(-1) {
	}
	Node(int key_, int left_, int right_) :
			key(key_), left(left_), right(right_) {
	}
};

vector<Node> tree;
vector<int> sorted;
void inOrder(int x) {
	if (x == -1)
		return;
	inOrder(tree[x].left);
//	cout<<tree[x].key<<endl;
	sorted.push_back(tree[x].key);
	inOrder(tree[x].right);
}

bool IsBinarySearchTree() {
	inOrder(0);


	for (int i = 0; i < SZ(sorted)-1; ++i) {
		if (sorted[i] > sorted[i + 1])
			return false;
	}

	return true;
}

int main() {

	ios_base::sync_with_stdio(0);

	int nodes;
	cin >> nodes;
	for (int i = 0; i < nodes; ++i) {
		int key, left, right;
		cin >> key >> left >> right;
		tree.push_back(Node(key, left, right));
	}

	if (nodes==0||IsBinarySearchTree()) {
		cout << "CORRECT" << endl;
	} else {
		cout << "INCORRECT" << endl;
	}
	return 0;
}

