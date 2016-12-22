//============================================================================
// Name        : 2240.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tm;
int length;
int arr[3][1001] = { { 0, }, };

int dp[1001][3][31] = { };

int main() {
	scanf("%d %d", &tm, &length);
	for (int i = 1; i <= tm; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp == 1) {
			arr[1][i] = 1;
		} else {
			arr[2][i] = 1;
		}
	}

//	dp[1][1][0] = arr[1][1];
//	dp[1][2][1] = arr[2][1];

	for (int t = 1; t <= tm; t++) {
		for(int l = 1 ; l <= 2 ; l++){
			for(int c = 0 ; c <= length ; c++){
//				if(c > t){
//					break;
//				}
				int m;

				if(l == 1){
//					if(c != 0){
						m = max(dp[t - 1][1][c], dp[t - 1][2][c - 1]);
//					}else{
//						m = max(dp[t - 1][1][c], 0);
//					}
				}else{
//					if(c != 0){
						m = max(dp[t - 1][1][c - 1], dp[t - 1][2][c]);
//					}else{
//						m = max(0, dp[t - 1][2][c]);
//					}
				}
				dp[t][l][c] = m + arr[t][l];
			}
		}
//		for (int c = 0; c <= cnt; c++) {
//			if (arr[t][1] == 1) {
//				dp[t][1][c] = max(dp[t - 1][2][c - 1] + 1, dp[t - 1][1][c] + 1);
//				dp[t][2][c] = max(dp[t - 1][1][c - 1], dp[t - 1][2][c]);
//
//			} else {
//				dp[t][1][c] = max(dp[t -1][2][c - 1], dp[t -1][1][c]);
//				dp[t][2][c] = max(dp[t - 1][1][c - 1] + 1, dp[t - 1][2][c] + 1);
//			}
//		}

	}

	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= length; j++) {
			printf("%d ", dp[tm][i][j]);
		}
		cout << endl;
	}

	cout << *max_element(&dp[tm][1][0], &dp[tm][2][length] + 1);

	return 0;
}
