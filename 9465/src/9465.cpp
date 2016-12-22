//============================================================================
// Name        : 9465.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int testcase;
int size;
int arr[3][100001] = { { 0, }, };
int dp[3][100001] = { { 0, }, };

queue<int> results;

int main() {
	cin >> testcase;

	for (int k = 1; k <= testcase; k++) {
		cin >> size;

		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= size; j++) {
				cin >> arr[i][j];
			}
		}

		dp[1][1] = arr[1][1], dp[2][1] = arr[2][1];
		for (int n = 1; n <= size; n++) {
			dp[1][n] = max(dp[2][n - 1], dp[2][n - 2]) + arr[1][n];
			dp[2][n] = max(dp[1][n - 1], dp[1][n - 2]) + arr[2][n];
		}

//		for (int i = 1; i <= 2; i++) {
//			for (int j = 1; j <= size; j++) {
//				cout << dp[i][j] << " ";
//			}
//			cout << endl;
//		}

		results.push(max(dp[1][size], dp[2][size]));
	}

	while (!results.empty()) {
		cout << results.front() << endl;
		results.pop();
	}

	return 0;
}
