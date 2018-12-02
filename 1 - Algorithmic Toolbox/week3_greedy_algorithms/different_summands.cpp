#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()

vector<int> optimal_summands(int n) {
	vector<int> summands;
	int i = 1;
	while (n) {
		if (n - i >= 0) {
			n -= i;
			summands.push_back(i);
		} else {
			break;
		}
		i++;
	}
	summands[SZ(summands) - 1] += n;

	return summands;
}
int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
