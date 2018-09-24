#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(s) (int)s.size()
#define ALL(v) v.begin(), v.end()

struct Segment {
	int start, end;
	bool operator<(const Segment& s) const {
		if (start < s.start)
			return true;
		if (start == s.start)
			return end > s.end;
		return false;
	}
};

vector<int> optimal_points(vector<Segment> &segments) {

	sort(ALL(segments));
	vector<int> points;

	int x = 0;
	int y = 1e9 + 1;

	//write your code here
	for (size_t i = 0; i < segments.size(); ++i) {
		if ((segments[i].start >= x && segments[i].start <= y)
				|| (segments[i].end >= x && segments[i].end <= y)) {
			x = max(segments[i].start, x);
			y = min(segments[i].end, y);
		} else {
			points.push_back(y);
			x = segments[i].start;
			y = segments[i].end;
		}
	}
	points.push_back(y);

	return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
