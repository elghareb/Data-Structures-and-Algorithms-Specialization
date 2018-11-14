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

int distance(int s, int t) {
	bool vis[100001];
	queue<int> q;
	clr(vis, 0);

	q.push(s);
	vis[s] = 1;
	int cnt = 0;
	while (!q.empty()) {
		cnt++;
		int sz = q.size();
		while (sz--) {
			int u = q.front();
			q.pop();
			for (auto v : adj[u]) {
				if (v == t) {
					return cnt;
				}
				if (!vis[v]) {
					q.push(v);
					vis[v] = 1;

				}
			}
		}
	}
	return -1;
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
	int s, t;
	std::cin >> s >> t;
	s--, t--;
	std::cout << distance(s, t);

	return 0;
}

