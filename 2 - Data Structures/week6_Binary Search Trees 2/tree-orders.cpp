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

class TreeOrders {
	int n;
	vector<int> key;
	vector<int> left;
	vector<int> right;

public:
	void read() {
		cin >> n;
		key.resize(n);
		left.resize(n);
		right.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> key[i] >> left[i] >> right[i];
		}
	}

	vector<int> inOrder;
	vector<int> postOrder;
	vector<int> preOrder;

	void travers(int x) {
		if (x == -1) {
			return;
		}
		preOrder.push_back(key[x]);
		travers(left[x]);
		inOrder.push_back(key[x]);
		travers(right[x]);
		postOrder.push_back(key[x]);

	}
};

void print(vector<int> a) {
	for (size_t i = 0; i < a.size(); i++) {
		if (i > 0) {
			cout << ' ';
		}
		cout << a[i];
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	TreeOrders t;
	t.read();
	t.travers(0);
	print(t.inOrder);
	print(t.preOrder);
	print(t.postOrder);
	return 0;
}




