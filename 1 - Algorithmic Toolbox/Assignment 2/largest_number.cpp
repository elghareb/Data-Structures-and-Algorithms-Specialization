#include <bits/stdc++.h>
using namespace std;
#define ALL(c) c.begin(), c.end()
#define clr(a,b) memset(a,b,sizeof a)

string largest_number(vector<string> a) {
	//write your code here

	// sort by lexographical

	sort(ALL(a),greater<string>());

	stringstream ret;

	for (size_t i = 0; i < a.size(); i++) {
		ret << a[i];
	}
	string result;
	ret >> result;
	return result;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<string> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		cin >> a[i];
	}
	cout << largest_number(a);
}



