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
vector<int> adj[100001];

int bipartite() {
	int vis[100001];
	queue<int> q;
	clr(vis, -1);
	q.push(0);
	vis[0] = 1;
	while (!q.empty()) {
		int u = q.front();
		int c = 1-vis[u];
		q.pop();

		for (auto v : adj[u]) {
			if (vis[v] == -1) {
				vis[v] = c;
				q.push(v);
			} else {
				if (vis[v] != c) {
					return 0;
				}
			}
		}
	}
	return 1;
}

int main() {

	int n, m;
	std::cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	std::cout << bipartite();

	return 0;
}

