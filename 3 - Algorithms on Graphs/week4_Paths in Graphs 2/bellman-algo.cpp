vector<pair<int, int>> adj[1001];
ll dist[1001];
bool vis[1001];
int prev[1001];


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
void bellmanFord2() {

}