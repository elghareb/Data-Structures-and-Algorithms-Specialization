#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)

vector<int> a;
vector<int> b;
vector<int> c;
int memo[101][101][101];

int lcs2(int i, int j, int k) {
	if (i == SZ(a) || j == SZ(b) || SZ(c) == k) {
		return 0;
	}
	int &ret = memo[i][j][k];

	if (ret != -1)
		return ret;

	int common = 0;
	if (a[i] == b[j] && b[j] == c[k]) {
		common = lcs2(i + 1, j + 1, k + 1) + 1;
	}
	int diff = lcs2(i + 1, j, k);
	diff = max(diff, lcs2(i, j + 1, k));
	diff = max(diff, lcs2(i, j, k + 1));

	return ret = max(common, diff);
}

int main() {
	clr(memo, -1);
	size_t n, m, o, x;
	std::cin >> n;
	for (size_t i = 0; i < n; i++) {
		std::cin >> x;
		a.push_back(x);
	}
	std::cin >> m;
	for (size_t i = 0; i < m; i++) {
		std::cin >> x;
		b.push_back(x);
	}
	std::cin >> o;
	for (size_t i = 0; i < o; i++) {
		std::cin >> x;
		c.push_back(x);
	}
	std::cout << lcs2(0, 0, 0) << std::endl;
}
