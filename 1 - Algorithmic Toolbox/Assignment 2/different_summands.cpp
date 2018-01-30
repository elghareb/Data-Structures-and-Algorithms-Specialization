#include <bits/stdc++.h>

using namespace std;

#define ALL(c) c.begin(), c.end()
#define clr(a,b) memset(a,b,sizeof a)

vector<int> optimal_summands(int n) {
	vector<int> summands;

	// conclusion from pattern
	// 1 + 2 + 3 + ..... n = n(n+1)/2

	ll sum = 0;
	for (int i = 1; i <= sqrt(n + 1); ++i) {
		summands.push_back(i);
		sum += i;
	}
	if (n - sum > summands[(int) summands.size() - 1]) {
		summands.push_back(n - sum);
	} else {
		summands[(int) summands.size() - 1] += n - sum;
	}

	return summands;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n;
	std::cin >> n;
	vector<int> summands = optimal_summands(n);
	std::cout << summands.size() << '\n';
	for (size_t i = 0; i < summands.size(); ++i) {
		std::cout << summands[i] << ' ';
	}
}



