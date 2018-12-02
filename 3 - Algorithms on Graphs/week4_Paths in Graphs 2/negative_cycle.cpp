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
const ll OO = (1LL << 60);
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
///////////////////////////////////////
vector<pair<int, int>> adj[10001];
ll dist[10001];
bool vis[10001];
int prev[10001];

vector<pair<int, int>> edges;

bool bellmanFord1(int n) {

	for (int i = 0; i < n - 1; i++) // relax all E edges V-1 times
		for (int u = 0; u < n; u++) // these two loops = O(E), overall O(VE)
			for (int j = 0; j < sz(adj[u]); j++) {
				auto v = adj[u][j]; // record SP spanning here if needed
				dist[v.first] = min(dist[v.first], dist[u] + v.second); // relax
			}

	bool hasNegativeCycle = false;

	for (int u = 0; u < n; u++) // one more pass to check
		for (int j = 0; j < sz(adj[u]); j++) {
			auto v = adj[u][j];
			if (dist[v.first] > dist[u] + v.second) // if this is still possible
				hasNegativeCycle = true;	// then negative cycle exists!
		}

	return hasNegativeCycle;
}


int main() {

	int n, m;
	std::cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, w;
		std::cin >> x >> y >> w;
		adj[x - 1].push_back( { y - 1, w });

	}
	std::cout << bellmanFord1(n);

	return 0;
}

