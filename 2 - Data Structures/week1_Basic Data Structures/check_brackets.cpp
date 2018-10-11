#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()
#define clr(a,v) memset(a,v,sizeof a)
///////////////////////////////////////

struct Bracket {
	Bracket(char type, int position) :
			type(type), position(position) {
	}

	bool Matchc(char c) {
		if (type == '[' && c == ']')
			return true;
		if (type == '{' && c == '}')
			return true;
		if (type == '(' && c == ')')
			return true;
		return false;
	}

	char type;
	int position;
};
int main() {


	ios_base::sync_with_stdio(0);
	std::string text;
	getline(std::cin, text);

	std::stack<Bracket> opening_brackets_stack;
	for (int position = 0; position < text.length(); ++position) {
		char next = text[position];

		if (next == '(' || next == '[' || next == '{') {
			Bracket nw { next, position };
			opening_brackets_stack.push(nw);
		}

		if (next == ')' || next == ']' || next == '}') {
			if (opening_brackets_stack.empty()) {
				cout << position + 1 << endl;
				return 0;
			} else {
				Bracket last = opening_brackets_stack.top();
				if (last.type == '(' && next == ')') {
					opening_brackets_stack.pop();
				} else if (last.type == '[' && next == ']') {
					opening_brackets_stack.pop();
				} else if (last.type == '{' && next == '}') {
					opening_brackets_stack.pop();
				} else {
					cout << position + 1 << endl;
					return 0;
				}
			}
		}
	}


	if (SZ(opening_brackets_stack)) {
		cout << opening_brackets_stack.top().position + 1 << endl;
	} else
		cout << "Success" << endl;

	return 0;
}
