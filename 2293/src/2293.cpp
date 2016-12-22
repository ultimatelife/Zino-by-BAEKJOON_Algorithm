/*
문제
n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그 경우의 수를 구하시오. (각각의 동전은 몇 개라도 사용할 수 있다.)

입력
첫째줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다.

출력
첫째 줄에 경우의 수를 출력한다. 경우의 수는 2^31보다 작다.

예제 입력  복사
3 10
1
2
5
예제 출력  복사
10
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
int coins[101] = {0,};
int dp[10001] = {0,};

int main() {
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> coins[i];
    }
    dp[0] = 1;

    for(int i = 1 ; i<= n ; i++){
    	for(int j = 1 ; j <= k ; j++){
    		if(j - coins[i] >= 0){
    			dp[j] += dp[j - coins[i]];
    		}
    	}
    }
    cout << dp[k] << endl;


    return 0;
}
