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

class HeapBuilder {
private:
	vector<int> data_;
	vector<pair<int, int> > swaps_;

	void WriteResponse() const {
		cout << SZ(swaps_)<< "\n";
		for (int i = 0; i < SZ(swaps_); ++i) {
			cout << swaps_[i].first << " " << swaps_[i].second << "\n";
		}
	}

	void ReadData() {
		int n;
		cin >> n;
		data_.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> data_[i];
	}

	int LChild(int i) {
		return 2 * i + 1;
	}
	int RChild(int i) {
		return 2 * i + 2;
	}
	int partent(int i) {
		return (i - 1) / 2;
	}

	void siftUp(int i) {
		while (i > 0 && data_[partent(i)] > data_[i]) {
			swap(data_[i], data_[partent(i)]);
			i = partent(i);
		}
	}
	void siftDown(int i) {
		int mnIndex = i;
		int l = LChild(i);
		int r = RChild(i);
		if (l < SZ(data_) && data_[l] < data_[mnIndex]) {
			mnIndex = l;
		}
		if (r < SZ(data_) && data_[r] < data_[mnIndex]) {
			mnIndex = r;
		}
		if (i != mnIndex) {
			swap(data_[i], data_[mnIndex]);
			swaps_.push_back( {i, mnIndex});
			siftDown(mnIndex);
		}
	}
	void GenerateSwaps() {
		swaps_.clear();
		// The following naive implementation just sorts
		// the given sequence using selection sort algorithm
		// and saves the resulting sequence of swaps.
		// This turns the given array into a heap,
		// but in the worst case gives a quadratic number of swaps.
		//
		// TODO: replace by a more efficient implementation
		for (int i = SZ(data_) / 2; i >= 0; --i) {
			siftDown(i);
		}
	}

public:
	void Solve() {
		ReadData();
		GenerateSwaps();
		WriteResponse();
	}
};


int main() {


	ios_base::sync_with_stdio(0);
	HeapBuilder heap_builder;
	heap_builder.Solve();

	return 0;
}
