
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int t,m;
int arr[1001][3] = {{0,},};
int dp[1001][31][3] = {{{0,},},};

int main() {
    cin >> t >> m;
    for (int i = 1 ; i <= t ; i++) {
        int x;
        cin >> x;
        arr[i][x] = 1;
    }

    for (int i = 1 ; i <= t; i++) {
        for (int j = 0 ; j <= m; j++) {
            if(j - 1 >= 0){
                dp[i][j][1] = max(dp[i - 1][j - 1][2], dp[i - 1][j][1]) + arr[i][1];
                dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]) + arr[i][2];
            }else{
                dp[i][j][1] = dp[i - 1][j][1] + arr[i][1];
                dp[i][j][2] = dp[i - 1][j][2] + arr[i][2];
            }

        }
    }

    int result = *max_element(&dp[t][0][1], &dp[t][m][2] + 1);
    cout << result << endl;

    return 0;
}
