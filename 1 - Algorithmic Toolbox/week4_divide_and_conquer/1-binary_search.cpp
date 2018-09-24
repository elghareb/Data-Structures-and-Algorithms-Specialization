#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)

int binary_search(const vector<int> &a, int x) {
	int left = 0, right = (int) a.size()-1;
	int mid ;
	while (left < right) {


		mid = left + (1+right - left) / 2;

		if(a[mid]<=x){
			left=mid;
		}else{
			right=mid-1;
		}

	}
	if(a[right]==x){
		return right;
	}

	return -1;
}

int linear_search(const vector<int> &a, int x) {
	for (size_t i = 0; i < a.size(); ++i) {
		if (a[i] == x)
			return i;
	}
	return -1;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	int m;
	std::cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		std::cin >> b[i];
	}
	for (int i = 0; i < m; ++i) {
		//replace with the call to binary_search when implemented
		std::cout << binary_search(a, b[i]) << ' ';
	}
}
