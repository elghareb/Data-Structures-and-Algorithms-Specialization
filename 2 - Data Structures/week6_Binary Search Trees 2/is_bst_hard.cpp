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

bool check(int current, ll mn, ll mx) {

	int key = tree[current].key;
	int left = tree[current].left;
	int right = tree[current].right;

	int keyLeft = (left != -1) ? tree[left].key : -1;
	int keyRight = (right != -1) ? tree[right].key : -1;

	if (key < mn || key >= mx) {
		return false;
	}

	bool c = true;

	if (c && keyLeft != -1)
		c = c && check(left, mn, key);

	if (c && keyRight != -1)
		c = c && check(right, key, mx);

	return c;
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

	if (nodes == 0 || check(0, -1e10, 1e10)) {
		cout << "CORRECT" << endl;
	} else {
		cout << "INCORRECT" << endl;
	}

	return 0;
}

