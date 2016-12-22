/*
 * 문제
 정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

 X가 3으로 나누어 떨어지면, 3으로 나눈다.
 X가 2로 나누어 떨어지면, 2로 나눈다.
 1을 뺀다.
 정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만드려고 한다. 연산을 사용하는 횟수의 최소값을 출력하시오.

 입력
 첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 자연수 N이 주어진다.

 출력
 첫째 줄에 연산을 하는 횟수의 최소값을 출력한다.

 *
 */
#include <iostream>
using namespace std;

int row;
int col;

int arr[501][501] = { {0,}, };
int dp[501][501] = { {0,}, };

const int moveX[4] = { 1, -1, 0, 0 };
const int moveY[4] = { 0, 0, 1, -1 };

int find(int x, int y){
    if(dp[x][y]){
    	return dp[x][y];
    }

    if(x == row && y == col){
        return 1;
    }

    for(int dir = 0 ; dir < 4 ; dir++){
        int tx = x + moveX[dir], ty = y + moveY[dir];
        if(tx == 0 || tx > row || ty == 0 || ty > col){
            continue;
        }

        if(arr[x][y] > arr[tx][ty]){
            dp[x][y] += find(tx, ty);
        }
    }
    return dp[x][y];
}

int main() {
	scanf("%d %d", &row, &col);

    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            scanf("%d", &arr[i][j]) ;
        }
    }

    printf("%d\n", find(1,1));

    return 0;
}
