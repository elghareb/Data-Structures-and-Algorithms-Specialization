#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define clr(a,v) memset(a,v,sizeof a)
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x) * (x))

///////////////////////////////////////

vector<int> computePrefixFunction(string p) {
	vector<int> s(SZ(p));
	s[0] = 0;
	int border = 0;

	for (int i = 1; i < SZ(p); ++i) {
		while (border > 0 && p[i] != p[border]) {
			border = s[border - 1];
		}
		if (p[i] == p[border]) {
			border++;
		} else {
			border = 0;
		}
		s[i] = border;
	}
	return s;
}
vector<int> find_pattern(const string& pattern, const string& text) {
	string p = pattern + '&' + text;

	vector<int> result;
	vector<int> ans = computePrefixFunction(p);

	for (int i = SZ(pattern); i < SZ(ans); ++i) {
		if (ans[i] == SZ(pattern)) {
			result.push_back(i - 2*SZ(pattern) );
		}
	}
	// Implement this function yourself
	return result;
}

int main() {

	string pattern, text;
	cin >> pattern;
	cin >> text;
	vector<int> result = find_pattern(pattern, text);
	for (int i = 0; i < result.size(); ++i) {
		printf("%d ", result[i]);
	}
	printf("\n");
	return 0;
}

