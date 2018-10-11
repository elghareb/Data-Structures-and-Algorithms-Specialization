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

class JobQueue {
private:
	int num_workers_;
	vector<int> jobs_;

	vector<int> assigned_workers_;
	vector<long long> start_times_;

	void WriteResponse() const {
		for (int i = 0; i < jobs_.size(); ++i) {
			cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
		}
	}

	void ReadData() {
		int m;
		cin >> num_workers_ >> m;
		jobs_.resize(m);
		for (int i = 0; i < m; ++i)
			cin >> jobs_[i];
	}

	void AssignJobs() {
		// TODO: replace this code with a faster algorithm.
		assigned_workers_.resize(jobs_.size());
		start_times_.resize(jobs_.size());

		priority_queue<pair<ll, int>, vector<pair<ll, int>>,
				greater<pair<ll, int>> > p;
		for (int i = 0; i < num_workers_; ++i) {
			p.push( { 0, i });

		}
		for (int i = 0; i < SZ(jobs_); ++i) {
			auto it = p.top();
			p.pop();
			start_times_[i] = it.first;
			assigned_workers_[i] = it.second;
			p.push( { jobs_[i] + it.first, it.second });
		}

	}

public:
	void Solve() {
		ReadData();
		AssignJobs();
		WriteResponse();
	}
};

int main() {


	ios_base::sync_with_stdio(0);
	std::ios_base::sync_with_stdio(false);
	JobQueue job_queue;
	job_queue.Solve();




	return 0;
}
