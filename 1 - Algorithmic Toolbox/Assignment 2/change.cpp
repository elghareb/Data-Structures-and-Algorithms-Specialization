#include <iostream>

int get_change(int m) {
	int c[] = { 10, 5, 1 };
	int ans = 0;
	int n = 0;
	for (int i = 0; i < 3; ++i) {
		if (m - c[i] >= 0) {
			n += m / c[i];
			m = m % c[i];
		}
	}
	return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
