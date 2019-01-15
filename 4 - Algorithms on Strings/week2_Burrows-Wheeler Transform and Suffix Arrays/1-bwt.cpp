#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string BWT(string text) {
	string result = "";

	vector<string> str;
	for (int i = 0; i < SZ(text); ++i) {
		str.push_back(text);
		rotate(text.begin(), text.begin() + 1, text.end());
	}

	sort(ALL(str));
	for (auto st : str) {
		result += st[SZ(st) - 1];
	}

	return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}