//============================================================================
// Name        : 2225.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
long long dp[201][201];

long long findDP(int num, int cnt){
    if(dp[num][cnt] != 0){
        return dp[num][cnt];
    }

    for(int i = 0 ; i <= num ; i++){
        dp[num][cnt] += findDP(i, cnt - 1);
        dp[num][cnt] %= 1000000000;
    }

    return (dp[num][cnt]) % 1000000000;
}

int main() {
    cin >> n >> k;

    for(int i = 0 ; i <= n ; i++){
        dp[i][1] = 1;
    }

    cout << findDP(n, k) << endl;

    return 0;
}
