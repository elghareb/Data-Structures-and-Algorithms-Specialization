#include <bits/stdc++.h>

using namespace std;

#define ALL(c) c.begin(), c.end()
#define clr(a,b) memset(a,b,sizeof a)

long long max_dot_product(vector<int> a, vector<int> b) {
	// write your code here
	long long result = 0;
	sort(ALL(a),greater<int>());
	sort(ALL(b),greater<int>());
	for (size_t i = 0; i < a.size(); i++) {
		result += ((long long) a[i]) * b[i];
	}
	return result;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
#endif
	size_t n;
	std::cin >> n;
	vector<int> a(n), b(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (size_t i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	std::cout << max_dot_product(a, b) << std::endl;
}



