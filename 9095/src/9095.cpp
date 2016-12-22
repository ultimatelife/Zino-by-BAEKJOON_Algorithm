//============================================================================
// Name        : 9095.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int t,n;
int dp[12] = {0,};

int findResult(int n){
	if(dp[n] != 0)
		return dp[n];
	if(n == 0)
		return 0;
	dp[n] = findResult(n - 1) + findResult(n -2) + findResult(n -3);
	return dp[n];
}

int main() {
	cin >> t;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while(t--){
		cin >> n;
		cout << findResult(n) << endl;
	}


	return 0;
}
