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
string InverseBWT(const string& bwt) {
	string text = "";
	vector<pair<char, int> > cols;

	for (int i = 0; i < SZ(bwt); i++) {
		cols.push_back( { bwt[i], i });
	}
	sort(cols.begin(), cols.end());



	auto symbol = cols[0];
	for (int i = 0; i < SZ(bwt); i++) {
		symbol = cols[symbol.second];
		text += symbol.first;
	}
	return text;
}

int main() {
	string bwt;
	cin >> bwt;
	cout << InverseBWT(bwt) << endl;
	return 0;
}

