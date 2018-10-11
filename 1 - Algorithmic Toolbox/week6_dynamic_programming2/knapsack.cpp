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
int dp[301][10001];


int optimal_weight(int W, const vector<int> &w) {

	clr(dp, 0);
	for (int i = 1; i <= SZ(w); ++i) {
		for (int j = 1; j <= W; ++j) {
			if (j - w[i - 1] >= 0)
				dp[i][j] = max(dp[i - 1][j],
						dp[i - 1][j - w[i - 1]] + w[i - 1]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[SZ(w)][W];
}

int main() {

	int n, W;
	std::cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		std::cin >> w[i];
	}
	std::cout << optimal_weight(W, w) << '\n';

	return 0;
}
