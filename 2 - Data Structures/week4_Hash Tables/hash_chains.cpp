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
	string type, s;
	size_t ind;
};

class QueryProcessor {
	vector<vector<string>> chaining;
	int bucket_count;
	// store all strings in one vector

	size_t hash_func(const string& s) const {
		static const size_t multiplier = 263;
		static const size_t prime = 1000000007;
		unsigned long long hash = 0;
		for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i)
			hash = (hash * multiplier + s[i]) % prime;
		return hash % bucket_count;
	}

public:
	explicit QueryProcessor(int bucket_count) :
			bucket_count(bucket_count) {
		chaining.resize(bucket_count + 2);

	}

	Query readQuery() const {
		Query query;
		cin >> query.type;
		if (query.type != "check")
			cin >> query.s;
		else
			cin >> query.ind;
		return query;
	}

	void writeSearchResult(bool was_found) const {
		std::cout << (was_found ? "yes\n" : "no\n");
	}

	void processQuery(const Query& query) {
		size_t hInt = hash_func(query.s);
		if (query.type == "check") {
			// use reverse order, because we append strings to the end
			for (int i = SZ(chaining[query.ind]) - 1; i >= 0; --i) {
				std::cout << chaining[query.ind][i] << " ";
			}
			std::cout << "\n";
		} else {

			if (query.type == "find") {
				for (auto it : chaining[hInt]) {
					if (it == query.s) {
						writeSearchResult(true);
						return;
					}
				}
				writeSearchResult(false);
			} else if (query.type == "add") {
				for (auto it : chaining[hInt]) {
					if (it == query.s) {
						return;
					}
				}
				chaining[hInt].push_back(query.s);

			} else if (query.type == "del") {
				vector<string>::iterator it = std::find(chaining[hInt].begin(),
						chaining[hInt].end(), query.s);
				if (it != chaining[hInt].end())
					chaining[hInt].erase(it);

			}
		}
	}

	void processQueries() {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			processQuery(readQuery());
	}
};

int main() {

	ios_base::sync_with_stdio(0);
	int bucket_count;
	cin >> bucket_count;
	QueryProcessor proc(bucket_count);
	proc.processQueries();

	return 0;
}
