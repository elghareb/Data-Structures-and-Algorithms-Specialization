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
priority_queue<pair<int, int>> pq; // priority queue to help choose shorter edges

void process(int vtx) {
	vis[vtx] = 1;
	for (auto v : adj[vtx]) {
		if (!vis[v.first])
			pq.push( { -v.second, -v.first });
	}
}
double primes() {
	process(0);
	double mst_cost = 0;
	while (!pq.empty()) { // repeat until V vertices (E=V-1 edges) are taken
		auto front = pq.top();
		pq.pop();
		auto u = -front.second, w = -front.first; // negate the id and weight again
		if (!vis[u]) // we have not connected this vertex yet
			mst_cost += sqrt(w), process(u); // take u, process all edges incident to u
	}
	return mst_cost;
//	printf("MST cost = %d (Prim’s)\n", mst_cost);
}
double minimum_distance(vector<int> x, vector<int> y) {
	double result = 0.;
	for (int i = 0; i < sz(x) - 1; ++i) {
		for (int j = i + 1; j < sz(x); ++j) {
			if (i == j)
				continue;
			double xx = x[i] - x[j];
			xx *= xx;
			double yy = y[i] - y[j];
			yy *= yy;
			adj[i].push_back( { j, xx + yy });
			adj[j].push_back( { i, xx + yy });

		}
	}
	clr(vis, 0);
	result = primes();
	return result;
}
int main() {
	size_t n;
	std::cin >> n;
	vector<int> x(n), y(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> x[i] >> y[i];
	}
	std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;

	return 0;
}

