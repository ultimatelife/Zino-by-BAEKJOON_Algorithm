/*
 문제
 n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다. (각각의 동전은 몇개라도 사용할 수 있다.)

 입력
 첫째줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다.

 출력
 첫째줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 -1을 출력한다.

 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num;
int money;
int coins[10001] = { 0, };
int dp[10001] = { 0, };

int main() {
    cin >> num >> money;
    for (int i = 1; i <= num; i++) {
        scanf("%d", &coins[i]);
    }
    fill(&dp[0], &dp[money] + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= money; j++) {
            if (j - coins[i] >= 0) {
                //dp[j - coins[i]] != -1
                if(dp[j] == -1 && dp[j - coins[i]] == -1){

                }else if(dp[j] == -1 && dp[j - coins[i]] != -1){
                    dp[j] = dp[j - coins[i]] + 1;
                }else if(dp[j] != -1 && dp[j - coins[i]] != -1){
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
    }
//    for (int i = 0; i <= money; i++) {
//        printf("%d ", dp[i]);
//    }
//    puts("");

    printf("%d\n", dp[money]);
    return 0;
}
