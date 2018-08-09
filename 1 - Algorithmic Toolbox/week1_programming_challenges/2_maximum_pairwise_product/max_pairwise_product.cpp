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

ll MaxPairwiseProduct(const std::vector<ll>& numbers) {
	ll max_product = 0;
	int n = numbers.size();
	int i = -1;
	int j = -1;
	ll mxi = -1;
	ll mxj = -1;

	for (int first = 0; first < n; ++first) {
		if (numbers[first] > mxi) {
			mxi = numbers[first];
			i = first;
		}
	}
	for (int second = 0; second < n; ++second) {
		if (second != i && numbers[second] > mxj) {
			mxj = numbers[second];
			j = second;
		}
	}

	return numbers[i] * numbers[j];
}

int main() {
	int n;
	std::cin >> n;
	std::vector<ll> numbers(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> numbers[i];
	}

	ll result = MaxPairwiseProduct(numbers);
	std::cout << result << "\n";
	return 0;
}

