//============================================================================
// Name        : 11444.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

long long num;
long long divnum = 1000000007;
long long dp[1001] = { 0, };

int main() {
	cin >> num;
	dp[1] = 1;

	for (long long i = 2; i <= num; i++) {
		long long v = i % 1000;

		if (v == 0) {
			dp[v] = (dp[999] + dp[998]) % divnum;
			continue;
		}

		if (v == 1) {
			dp[v] = (dp[0] + dp[999]) % divnum;
			continue;
		}
		dp[v] = (dp[v - 1] + dp[v -2]) % divnum;
	}

	cout << dp[num % 1000] << endl;

	return 0;
}
