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
vector<pair<int, int>> adj[1001];
ll dist[1001];
bool vis[1001];
int prev[1001];

int dijkstra2(int n,int s, int d) {
	priority_queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
		dist[i] = OO;
	dist[s] = 0;

	q.push( { 0, s });
	while (!q.empty()) {
		//choose node that minimum cost and not visited
		int parent = q.top().second;
		q.pop();
		if (vis[parent])
			continue;
		vis[parent] = 1;

		for (auto child : adj[parent]) {
			if (dist[parent] + child.second < dist[child.first]) {
				dist[child.first] = dist[parent] + child.second;
				q.push( { -dist[child.first], child.first });
			}
		}
	}
	return dist[d] != OO ? dist[d] : -1;
}


int main() {
	int n, m;
	std::cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, w;
		std::cin >> x >> y >> w;
		adj[x - 1].push_back( { y - 1, w });

	}
	int s, t;
	std::cin >> s >> t;
	s--, t--;
	std::cout << dijkstra2(n,s, t);

	return 0;
}

