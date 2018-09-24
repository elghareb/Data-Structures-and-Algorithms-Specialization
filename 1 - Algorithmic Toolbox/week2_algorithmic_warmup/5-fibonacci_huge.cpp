#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(s) (int)s.size()
typedef long long ll;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
bool check(vector<ll> v) {
	int sz = SZ(v) / 2;
	for (int i = 0; i < sz; ++i) {
		if (v[i] != v[sz + i])
			return false;
	}
	return true;
}
int get_fibonacci_huge(long long n, long long m) {
	vector<ll> fib;
	fib.push_back(0);
	fib.push_back(1);
	for (int i = 0; true; ++i) {
		if (i >= 2) {
			fib.push_back((fib[i - 1] + fib[i - 2]) % m);
		}
		if (SZ(fib) % 2 == 0) {
			if(check(fib))
				break;
		}
	}
	fib.resize(SZ(fib)/2);

	return fib[n % SZ(fib)];
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
