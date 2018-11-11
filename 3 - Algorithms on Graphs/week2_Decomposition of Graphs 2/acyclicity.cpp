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
bool rec[1001];
bool vis[1001];
vector<int> adj[1001];
int acyclic(int u) {
	if (rec[u]) {
		return 1;
	}
	rec[u] = true;
	for (auto v : adj[u]) {
		if (!vis[v]) {
			vis[v] = true;
			if (acyclic(v)) {
				return true;
			};
		}
	}
	rec[u] = false;

	return 0;
}
int main() {

	clr(vis, 0);
	clr(rec, 0);
	ios_base::sync_with_stdio(0);
	size_t n, m;
	std::cin >> n >> m;
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
	}
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			if (acyclic(i)) {
				cout << 1 << endl;
				return 0;
			}
		}
	}

	cout << 0 << endl;
	return 0;
}

