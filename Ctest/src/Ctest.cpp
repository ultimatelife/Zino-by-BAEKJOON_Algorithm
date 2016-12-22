//============================================================================
// Name        : Ctest.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <queue>
//#include <algorithm>


//priority_queue<pair<int, int>> questions;

int dp[2001][2001] = {};


int main() {
	int len = 0;
	int arr[2001];
	int qNum = 0;

	scanf("%d", &len);

	for(int i = 1 ; i <= len ; i++){
		scanf("%d", &arr[i]);
	}

	for(int i = 0 ; i <= len ; i++){
		dp[0][i] = 1;
		dp[1][i] = 1;
	}

	for(int numElement = 2 ; numElement <= len ; numElement++){
		for(int i = 1 ; i + numElement - 1 <= len; i++){
			if(arr[i] == arr[i + numElement - 1] && dp[numElement -2][i + 1]){
				dp[numElement][i] = 1;
			}
		}
	}

	scanf("%d", &qNum);
	for(int i = 0 ; i < qNum ; i++){
		int a,b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[b - a + 1][a]);
	}

	return 0;
}


