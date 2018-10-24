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
struct Query {
	string type, name;
	int number;
};

vector<Query> read_queries() {
	int n;
	cin >> n;
	vector<Query> queries(n);
	for (int i = 0; i < n; ++i) {
		cin >> queries[i].type;
		if (queries[i].type == "add")
			cin >> queries[i].number >> queries[i].name;
		else
			cin >> queries[i].number;
	}
	return queries;
}

void write_responses(const vector<string>& result) {
	for (size_t i = 0; i < result.size(); ++i)
		std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
	vector<string> result;
	// Keep list of all existing (i.e. not deleted yet) contacts.

	vector<string> directAddressing(10000001);
	for (size_t i = 0; i < queries.size(); ++i)
		if (queries[i].type == "add") {
			directAddressing[queries[i].number] = queries[i].name;
		} else if (queries[i].type == "del") {
			directAddressing[queries[i].number] = "";
		} else {
			string response = "not found";
			if (directAddressing[queries[i].number] != ""
					&& SZ(directAddressing[queries[i].number]) > 0) {
				response = directAddressing[queries[i].number];

			}
			result.push_back(response);
		}
	return result;
}
int main() {

	ios_base::sync_with_stdio(0);
	write_responses(process_queries(read_queries()));

	return 0;
}

