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
typedef long long ll;
typedef unsigned long long ull;
///////////////////////////////////////
const double PI = acos(-1.0);
const double EPS = 1e-9;
///////////////////////////////////////
const int OO = 1 * 1e9;
const int N = (1 << 17);
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
///////////////////////////////////////

vector<int> adj[1001];

vector<int> order;
int inOrder[1001];
int outOrder[1001];
bool vis[1001];
//dfs
void toposort(int u) {

	for (auto v : adj[u]) {
		if (!vis[v]) {
			vis[v] = 1;
			toposort(v);
		}
	}
	order.push_back(u);
}
//bfs
void toposort2(int uu) {

	queue<int> q;
	q.push(uu);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto it : adj[u]) {
			inOrder[it]--;
			if (inOrder[it] == 0) {
				q.push(it);
			}
		}
	}

}

int main() {

	clr(inOrder, 0);
	clr(outOrder, 0);
	clr(vis, 0);

	size_t n, m;
	std::cin >> n >> m;
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		outOrder[x - 1]++;
		inOrder[y - 1]++;
		adj[x - 1].push_back(y - 1);

	}

	for (size_t i = 0; i < n; ++i) {
		if (inOrder[i] == 0) {
			vis[i] = 1;
			toposort(i);
		}
	}
	reverse(all(order));

	for (size_t i = 0; i < order.size(); i++) {
		std::cout << order[i] + 1 << " ";
	}
	return 0;
}

