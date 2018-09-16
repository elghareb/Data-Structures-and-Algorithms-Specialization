#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()


int count(vector<int>&a, int x, int l, int r) {
	int cnt = 0;
	for (int i = l; i <= r; ++i) {
		if (a[i] == x) {
			cnt++;
		}
	}
	return cnt;
}
int majorityElementRec(vector<int>&a, int l, int r) {

	if (l == r) {
		return a[l];
	}
	int m = l + (r - l) / 2;

	int left = majorityElementRec(a, l, m);
	int right = majorityElementRec(a, m + 1, r);
	if (left == right) {
		return left;
	}
	int lcnt = count(a, left, l, r);
	int rcnt = count(a, right, l, r);
	return lcnt > rcnt ? left : right;
}

int get_majority_element(vector<int>&a, int l, int r) {
	int n = SZ(a);
	int ans = majorityElementRec(a, l, r);
	int cnt = count(a, ans, l, r);



	if (cnt >= (n / 2) + 1) {
		return 1;
	}

	return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
