#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////
#define SZ(s) (int)s.size()

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}
//0 1 2 6 5 0 4 3 4 0 5 6 2 1 0 0 9 8 4 5 0 6 7 6 0 5 4 8 9 0

int fibonacci_sum_squares(long long n) {
	vector<int> sumSqFib;
	vector<int> fib;
	fib.push_back(0);
	fib.push_back(1);

	int c = 0;
	int sum = 0;
	for (int i = 0; i <= 100; ++i) {
		if (i >= 2) {
			fib.push_back((fib[i - 1] + fib[i - 2]) % 10);
		}
		sum += (fib[i]*fib[i]);
		sum %=10;
		sumSqFib.push_back(sum);
		if(sum==0)
			c++;
		if(c==8){
			break;
		}
	}
	return sumSqFib[(n) % SZ(sumSqFib)];
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n);
}
