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
struct DisjointSetsElement {
	int size, parent, rank;

	DisjointSetsElement(int size = 0, int parent = -1, int rank = 0) :
			size(size), parent(parent), rank(rank) {
	}
};
struct DisjointSets {
	int size;
	int max_table_size;
	vector<DisjointSetsElement> sets;

	DisjointSets(int size) :
			size(size), max_table_size(0), sets(size) {
		for (int i = 0; i < size; i++)
			sets[i].parent = i;
	}

	int getParent(int table) {
		return sets[table].parent == table ?
				table : (sets[table].parent = getParent(sets[table].parent));
	}

	void merge(int destination, int source) {
		int realDestination = getParent(destination);
		int realSource = getParent(source);

		if (realDestination != realSource) {
			// merge two components
			// use union by rank heuristic
			// update max_table_size

			if (sets[realDestination].rank > sets[realSource].rank) {
				sets[realSource].parent = realDestination;
				sets[realDestination].size += sets[realSource].size;
				max_table_size = max(max_table_size,
						sets[realDestination].size);
			} else {
				sets[realDestination].parent = realSource;
				sets[realSource].size += sets[realDestination].size;
				if (sets[realDestination].rank == sets[realSource].rank) {
					sets[realDestination].rank++;
				}
				max_table_size = max(max_table_size, sets[realSource].size);
			}

		}
	}
};

int main() {


	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;

	DisjointSets tables(n);
	for (auto &table : tables.sets) {
		cin >> table.size;
		tables.max_table_size = max(tables.max_table_size, table.size);
	}

	for (int i = 0; i < m; i++) {
		int destination, source;
		cin >> destination >> source;
		--destination;
		--source;

		tables.merge(destination, source);
		cout << tables.max_table_size << endl;
	}

	return 0;
}
