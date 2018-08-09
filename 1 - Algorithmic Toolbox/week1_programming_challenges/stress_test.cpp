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
ll MaxPairwiseProduct(const std::vector<int>& numbers) {
	ll max_product = 0;
	int n = numbers.size();

	for (int first = 0; first < n; ++first) {
		for (int second = first + 1; second < n; ++second) {
			max_product = std::max(max_product,
					1LL*numbers[first] * numbers[second]);
		}
	}

	return max_product;
}
ll MaxPairwiseProductFast(const std::vector<int>& numbers) {
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

	return 1LL* numbers[i] * numbers[j];
}
int main() {

	while (true) {
		//minimum number is two
		int n = (rand() % 2) + 4;
		cout << n << endl;
		vector<int> a;
		for (int i = 0; i < n; ++i) {
			a.push_back(rand() % 100);
		}
		for (int i = 0; i < n; ++i) {
			cout << a[i] << " ";
		}
		cout << endl;
		int res1 = MaxPairwiseProduct(a);
		int res2 = MaxPairwiseProductFast(a);
		if (res1 != res2) {
			cout << "Wrong answer " << res1 << " " << res2 << endl;
			break;
		}else{
			cout << "OK"<<endl;
		}
	}

	return 0;
}
