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

bool vis[1001];
int reach(vector<vector<int> > &adj, int x, int y) {
	if (x == y) {
		return true;
	}
	bool r = false;
	vis[x] = true;
	for (auto it : adj[x]) {
		if (!vis[it]) {
			r |= reach(adj, it, y);
		}
	}
	return r;
}

int main() {

	ios_base::sync_with_stdio(0);
	clr(vis, 0);
	size_t n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	int x, y;
	std::cin >> x >> y;
	std::cout << reach(adj, x - 1, y - 1);

	return 0;
}

