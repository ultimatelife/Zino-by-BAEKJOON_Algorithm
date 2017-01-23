#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ll;

const int INF = 999999999;
int arr[101], dp[101][101];

int getResult(int index, int group, bool check){
    if (group == 0)
        return 0;
    
    if (2 * group - 1 > index || index < 1)
        return -INF;
    
    if (dp[index][group] != -INF)
        return dp[index][group];
    
    int result = -INF;
    result = max(result, getResult(index - 1, group, false) + arr[index]);
    
    if (check == true)
        result = max(result, getResult(index - 1, group, false));
    else
        result = max(result, getResult(index - 1, group - 1, true));
    
    printf("dp[%d][%d] : %d\n", index, group, result);
    
    return dp[index][group] = result;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    
    for (int i = 0 ; i <= n; i++)
        for (int j = 0 ; j <= n; j++)
            dp[i][j] = -INF;
    
    cout << getResult(n, k, true) << endl;;
    
    
    return 0;
}


