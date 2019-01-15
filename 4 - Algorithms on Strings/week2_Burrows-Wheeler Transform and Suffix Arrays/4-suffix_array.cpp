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
vector<int> BuildSuffixArray(const string& text) {
	vector<int> result;
	vector<pair<string, int> > suffix;
	for (int i = 0; i < text.size(); i++) {
		suffix.push_back( { text.substr(i), i });
	}
	sort(suffix.begin(), suffix.end());

	for (int i = 0; i < suffix.size(); i++) {
		result.push_back(suffix[i].second);
	}
	// Implement this function yourself
	return result;
}

int main() {
	string text;
	cin >> text;
	vector<int> suffix_array = BuildSuffixArray(text);
	for (int i = 0; i < suffix_array.size(); ++i) {
		cout << suffix_array[i] << ' ';
	}
	cout << endl;
	return 0;
}

