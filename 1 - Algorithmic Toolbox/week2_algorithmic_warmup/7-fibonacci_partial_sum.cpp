#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(s) (int)s.size()

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int fibonacci_sum(long long n) {

	if (n <= 0) {
		return 0;
	}
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

long long get_fibonacci_partial_sum(long long from, long long to) {

	from = fibonacci_sum(from - 1);
	to = fibonacci_sum(to);

	long long sum = (to - from + 10) % 10;

	return sum;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
