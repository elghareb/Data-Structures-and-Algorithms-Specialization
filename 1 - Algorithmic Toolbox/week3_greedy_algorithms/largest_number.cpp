#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()

int cmp(string a, string b) {
	string ab = a.append(b);
	string ba = b.append(a);
	return ab.compare(ba) > 0 ? 1 : 0;
}
string largest_number(vector<string> a) {
	//write your code here

	sort(ALL(a),cmp);
	std::stringstream ret;
	for (size_t i = 0; i < a.size(); i++) {
		ret << a[i];
	}
	string result;
	ret >> result;
	return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
