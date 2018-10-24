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

struct Data {
	string pattern, text;
};

Data read_input() {
	Data data;
	std::cin >> data.pattern >> data.text;
	return data;
}

void print_occurrences(vector<int> output) {
	for (size_t i = 0; i < output.size(); ++i)
		std::cout << output[i] << " ";
	std::cout << "\n";
}

vector<int> polyHashing(Data d) {
	vector<int> ans;
	string s = d.text;
	string p = d.pattern;
	int n = SZ(s);
	int m = SZ(p);

	ll prime = 10000007;
	ll base = 263;

	ll hashS = 0;
	ll hashP = 0;

	ll bigBase = 1;

	for (int i = 0; i < m - 1; i++)
		bigBase = (bigBase * base) % prime;

	for (int i = 0; i < m; ++i) {
		hashP = (base * hashP + p[i]) % prime;
		hashS = (base * hashS + s[i]) % prime;
	}
	int j = 0;
	for (int i = 0; i <= n - m; ++i) {
		if (hashS == hashP) {
			for (j = 0; j < m; j++) {
				if (s[i + j] != p[j])
					break;
			}
			if (j == m)
				ans.push_back(i);
		}

		//remove old one
		hashS = (hashS - s[i] * bigBase + prime) % prime;
		//shifting
		hashS = (base * hashS) % prime;
		//adding
		hashS = (hashS + s[i + m] + prime) % prime;
	}
	return ans;
}
int main() {



	ios_base::sync_with_stdio(0);

	print_occurrences(polyHashing(read_input()));
	return 0;
}

