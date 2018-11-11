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

void dfs(vector<vector<int> > &adj, int x) {
	vis[x] = true;
	for (auto it : adj[x]) {
		if (!vis[it]) {
			dfs(adj, it);
		}
	}
}

int number_of_components(vector<vector<int> > &adj,int n) {
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			dfs(adj, i);
			res++;
		}
	}
	return res;
}

int main() {

	ios_base::sync_with_stdio(0);
	size_t n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	std::cout << number_of_components(adj,n);

	return 0;
}

