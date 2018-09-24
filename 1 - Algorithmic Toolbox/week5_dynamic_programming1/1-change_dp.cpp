#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)

int get_change(int m) {
	int mnCoins[m+1];

	mnCoins[1] = 1;
	mnCoins[2] = 2;
	mnCoins[3] = 1;
	mnCoins[4] = 1;
	for (int i = 5; i <= m; ++i) {
		mnCoins[i] = min(mnCoins[i - 1], min(mnCoins[i - 3], mnCoins[i - 4]))
				+ 1;
	}
	return mnCoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
