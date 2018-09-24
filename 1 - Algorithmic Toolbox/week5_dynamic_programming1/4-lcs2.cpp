#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)
///////////////////////////////////////
typedef long long ll;
typedef unsigned long long ull;

vector<int> a;
vector<int> b;
int memo[101][101];

int lcs2(int i, int j) {
	if (i == SZ(a) || j == SZ(b)) {
		return 0;
	}
	int &ret = memo[i][j];

	if (ret != -1)
		return ret;

	int common = 0;
	if (a[i] == b[j]) {
		common = lcs2(i + 1, j + 1) + 1;
	}
	int diff = max(lcs2(i + 1, j), lcs2(i, j + 1));

	return ret = max(common, diff);
}

int main() {
	clr(memo, -1);
	size_t n, m, x;
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
	std::cout << lcs2(0, 0) << std::endl;
}
