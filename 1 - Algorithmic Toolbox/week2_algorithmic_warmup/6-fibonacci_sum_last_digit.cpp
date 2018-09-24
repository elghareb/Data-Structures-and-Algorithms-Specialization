#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(s) (int)s.size()

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
//61
//0 1 2 4 7 2 0 3 4 8 3 2 6 9 6 6 3 0 4 5 0 6 7 4 2 7 0 8 9 8 8 7 6 4 1 6 8 5 4 0 5 6 2 9 2 2 5 8 4 3 8 2 1 4 6 1 8 0 9 0 0

int fibonacci_sum(long long n) {
	vector<int> sumFib;
	vector<int> fib;

	sumFib.push_back(0);
	sumFib.push_back(1);
	fib.push_back(0);
	fib.push_back(1);

	int c = 0;
	int sum = 1;
	for (int i = 2; i <= 61; ++i) {
		if (i >= 2) {
			fib.push_back((fib[i - 1] + fib[i - 2]) % 10);
		}
		sum += (fib[i]);
		sum %= 10;
		if (sum == 0)
			c++;
		sumFib.push_back(sum);

		if (c == 7)
			break;
	}


	return sumFib[(n) % SZ(sumFib)];
}
int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum(n);
}
