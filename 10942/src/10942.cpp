#include <iostream>
using namespace std;

int num, testcase;
int arr[2001], dp[2001][2001];

int main() {
    scanf("%d", &num);
    for (int i = 1; i <= num; i++) {
        scanf("%d", &arr[i]);
        dp[1][i] = 1;
    }

    for (int i=1; i <= num - 1; i++) {
        if (arr[i] == arr[i+1]) {
            dp[2][i] = 1;
        }
    }

    scanf("%d", &testcase);
    for (int i = 3; i <= num; i++) {
        for (int j = 1; j + i - 1<= num; j++) {
            if (arr[j] == arr[j + i - 1] && dp[i - 2][j + 1]) {
                dp[i][j] = 1;
            }
        }
    }

    for(int i = 1 ; i <= testcase ; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[b - a + 1][a]);
    }

    return 0;
}
