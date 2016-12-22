//============================================================================
// Name        : 2579.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num;
int arr[301];
int dp[301];

int main() {
	cin >> num;
	for(int i =1 ; i<= num ; i++){
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for(int i = 3 ; i <= num ;i++){
		dp[i] = max(arr[i - 1] + dp[i - 3], dp[i -2]) + arr[i];
	}
	cout << dp[num] << endl;

	return 0;
}
