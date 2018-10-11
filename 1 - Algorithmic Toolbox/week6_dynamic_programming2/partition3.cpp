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

int dp[20][700][700];
vector<int> A;
int n, x, sum;

int partition3(int i, int sum1, int sum2) {
	if (i == n) {
		int sum3 = sum - (sum1 + sum2);
		if (sum1 == sum2 && sum2 == sum3) {
			return 1;
		} else {
			return 0;
		}
	}
	int &ans = dp[i][sum1][sum2];
	if (ans != -1)
		return ans;

	bool c1 = partition3(i + 1, sum1 + A[i], sum2);
	bool c2 = partition3(i + 1, sum1, sum2 + A[i]);
	bool c3 = partition3(i + 1, sum1, sum2);
	return ans = (c1 || c2 || c3);
}

int main() {


	clr(dp, -1);
	sum = 0;
	std::cin >> n;
	for (size_t i = 0; i < n; ++i) {
		cin >> x;
		A.push_back(x);
		sum += x;
	}

	std::cout << partition3(0, 0, 0) << '\n';
	return 0;
}
