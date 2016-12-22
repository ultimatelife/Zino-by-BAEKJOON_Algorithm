#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long num;
long long length = 1;

long long dp[1000001];

int main() {
    cin >> num;
    fill(&dp[1], &dp[num] + 1, 1);
    while(num >= pow(2, length)){
    	length++;
    }
    length--;

    dp[0] = 1;
    for(int i = 1 ; i <= length ; i++){
        int x = pow(2, i);
        for(int j = 1 ; j <= num ; j++){
            if(j - x >= 0){
                dp[j] += dp[j -x];
                dp[j] %=  1000000000;
            }
        }
    }
//    printf("cnt : %d\n", cnt);
    cout << dp[num] << endl;


    return 0;
}
