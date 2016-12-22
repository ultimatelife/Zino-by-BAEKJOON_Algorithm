//============================================================================
// Name        : Ctest.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <queue>
#include <string>
//#include <algorithm>

using namespace std;

//priority_queue<pair<int, int>> questions;

int dp[2501][2501] = { };
int re[2501] = { };

int main() {
	char cArr[2501];
	scanf("%s", &cArr);
	string arr = cArr;
	arr = " " + arr;
	int len = arr.length() - 1;
//	printf("len : %d", len);

	for (int i = 0; i <= len; i++) {
		dp[0][i] = 1;
		dp[1][i] = 1;
	}

	for (int numElement = 2; numElement <= len; numElement++) {
		for (int i = 1; i + numElement - 1 <= len; i++) {
			if (arr[i] == arr[i + numElement - 1]
					&& dp[numElement - 2][i + 1]) {
				dp[numElement][i] = 1;
			}
		}
	}

	re[0] = 0, re[1] = 1;
	for (int n = 2; n <= len; n++) {
		int min = -1, temp;

//		if(dp[n][1] == 1){
//			printf("re[%d] : %d\n", n, re[n]);
//			re[n] = min;
//			continue;
//		}

		for (int j = 1; j <= n; j++) {
//			printf("n = %d j = %d dp[%d][%d] = %d\n", n,j, j, n - j + 1, dp[j][n - j + 1]);
			if (dp[j][n - j + 1] == 1) {
				temp = re[n - j] + 1;
				if (min == -1 || temp < min) {
					min = temp;
				}
			}
		}
		re[n] = min;
//		printf("re[%d] : %d\n", n, re[n]);
	}

	printf("%d\n", re[len]);
	return 0;
}

