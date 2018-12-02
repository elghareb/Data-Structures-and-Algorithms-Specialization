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

vector<int> optimal_sequence(int n) {
	vector<int> sequence;
	int mnStep[n + 1];
	mnStep[0] = 0;
	mnStep[1] = 0;

	for (int i = 1; i <= n; ++i) {
		mnStep[i] = mnStep[i - 1] + 1;

		if (i % 3 == 0) {
			mnStep[i] = min(mnStep[i / 3] + 1, mnStep[i]);
		}
		if (i % 2 == 0) {
			mnStep[i] = min(mnStep[i / 2] + 1, mnStep[i]);
		}
	}
	sequence.push_back(n);
	while (n > 1) {
		if (n % 3 == 0 && mnStep[n] == mnStep[n / 3] + 1) {
			n = n / 3;
		} else if (n % 2 == 0 && mnStep[n] == mnStep[n / 2] + 1) {
			n = n / 2;
		} else {
			n = n - 1;
		}
		sequence.push_back(n);
	}
	reverse(ALL(sequence));
	return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
