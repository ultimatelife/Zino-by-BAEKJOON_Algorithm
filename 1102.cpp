/*
6
0 1 0 0 0 1
5 0 2 7 0 2
0 3 0 4 0 3
0 8 2 0 3 2
4 0 0 0 0 4
1 8 2 3 3 0
NNYNNY
5
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<cmath>

using namespace std;
typedef pair<int, int> P;
const int INF = 987654321;

int num, moreThanP, needP;
int arr[16][16];
//bool isWorking[17];
int startNumOfPossibile;

bitset<16> isWorking;
int dp[1<<16];

int dfs(){
    if (isWorking.count() >= moreThanP)
        return 0;
    
    if (dp[isWorking.to_ulong()] != -1)
        return dp[isWorking.to_ulong()];
    
    int &result = dp[isWorking.to_ulong()];
    result = INF;
    
    for (int i = 0; i < num; i++) {
        if (isWorking[i]) {
            for (int j = 0; j < num; j++) {
                if (!isWorking[j]) {
                    isWorking.set(j);
                    result = min(result, arr[i][j] + dfs());
                    isWorking.flip(j);
                    //                    printf("result : %d\n", result);
                }
            }
        }
    }
    
    return result;
}

int main()
{
    cin >> num;
    fill(&dp[0], &dp[(1 << num)], -1);
    isWorking.reset();
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> arr[i][j];
        }
    }
    
    string str;
    cin >> str;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'Y') {
            isWorking.set(i);
        }
    }
    cin >> moreThanP;
    
    int result = INF;
    result = min(result, dfs());
    
    
    
    if (result >= INF)
        printf("-1\n");
    else
        printf("%d\n", result);
    
    return 0;
}
