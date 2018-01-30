#include <bits/stdc++.h>

using namespace std;

#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)

double get_optimal_value(int capacity, vector<int> weights,
		vector<int> values) {
	double value = 0.0;

	vector<pair<double, int>> p;
	for (int i = 0; i < SZ(values); ++i) {
		p.push_back( { 1.0 * values[i] / weights[i], weights[i] });
	}
	int mn = 0;
	sort(ALL(p), greater<pair<double, int>>());
	for (int i = 0; i < SZ(values); ++i) {

		mn = min(capacity, p[i].second);
		value += mn * p[i].first;
		capacity -= mn;

	}

	return value;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}


