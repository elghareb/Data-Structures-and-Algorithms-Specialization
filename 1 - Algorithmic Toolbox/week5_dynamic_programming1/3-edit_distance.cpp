#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)
///////////////////////////////////////
typedef long long ll;
typedef unsigned long long ull;

string str1, str2;
int memo[101][101];
int edit_distance(int i, int j) {
	if (i == SZ(str1) || j == SZ(str2)) {
		return max(SZ(str1)-i,SZ(str2)-j);
	}
	int &ret = memo[i][j];
	if (ret != -1)
		return ret;

	int del = edit_distance(i + 1, j) + 1;
	int ins = edit_distance(i, j + 1) + 1;

	int c = 1e4;
	if (str1[i] == str2[j]) {
		c = edit_distance(i + 1, j + 1);
	} else {
		c = edit_distance(i + 1, j + 1) + 1;
	}

	return ret = min(min(del, ins), c);

}

int main() {
	clr(memo, -1);
	std::cin >> str1 >> str2;
	std::cout << edit_distance(0, 0) << std::endl;
  return 0;
}
