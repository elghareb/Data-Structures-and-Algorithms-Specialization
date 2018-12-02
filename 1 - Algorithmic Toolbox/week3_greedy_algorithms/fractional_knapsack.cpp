#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()

double get_optimal_value(int capacity, vector<pair<double, int>> valwe) {
	double value = 0.0;
	sort(ALL(valwe));
	reverse(ALL(valwe));
	for (auto it : valwe) {
		int mn = min(it.second, capacity);
		capacity -= mn;
		value += mn * it.first;
	}
	return value;
}



int main() {
	
	int n, x, y;
	int capacity;
	std::cin >> n >> capacity;
	vector<pair<double, int>> valwe;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		valwe.push_back( { (1.0 * x) / y, y });
	}

	double optimal_value = get_optimal_value(capacity, valwe);
	std::cout.precision(10);
	std::cout << optimal_value << std::endl;

  return 0;
}
