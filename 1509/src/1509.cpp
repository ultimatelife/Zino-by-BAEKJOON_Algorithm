/*
 문제
 세준이는 어떤 문자열을 팰린드롬으로 분할하려고 한다.

 예를 들어, ABACABA를 팰린드롬 분할하면, {A, B, A, C, A, B, A}, {A, BACAB, A}, {ABA, C, ABA}, {ABACABA}가 된다.

 분할의 개수의 최소값을 출력하는 프로그램을 작성하시오.

 입력
 첫째 줄에 문자열이 주어진다. 이 문자열의 최대길이는 2,500이다.

 출력
 첫째 줄에 팰린드롬 분할의 개수의 최소값을 출력한다

 예제 입력  복사
 BBCDDECAECBDABADDCEBACCCBDCAABDBADD
 예제 출력  복사
 22
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int num;
char cstr[2501];
string str;
int dp[2501][2501];
int dp2[2501];

//int recur(int x){
//    if(dp2[x] != -1){
//        return dp2[x];
//    }
//
//    if(x > num){
//        return 0;
//    }
//
//    int sum = 0;
//    for(int i = 1 ; i + x - 1 <= num ; i++){
//        if(dp[i][x] && i + x - 1 == num){
//            sum += 1;
//            continue;
//        }
//        if(dp[i][x]){
//            sum += recur(i + x);
//        }
//    }
//    dp2[x] = sum;
//    return sum;
//}

int main() {
    scanf("%s", cstr);
    str = cstr;
    str = " " + str;
    num = str.length() - 1;
    fill(&dp2[0], &dp2[num] + 1, -1);

    for (int i = 1; i <= num; i++) {
        dp[1][i] = 1;
    }

    for (int i= 1; i <= num - 1; i++) {
        if (str[i] == str[i+1]) {
            dp[2][i] = 1;
        }
    }

    for (int i = 3; i <= num; i++) {
        for (int j = 1; j + i - 1<= num; j++) {
            if (str[j] == str[j + i - 1] && dp[i - 2][j + 1]) {
                dp[i][j] = 1;
            }
        }
    }

    dp2[0] = 0;
    dp2[1] = 1;
    dp2[2] = dp[2][1] ? 1 : 2;

    for(int i = 3 ; i <= num ; i++){
        int min = 0, temp = 0;
        for(int j = 1; j <= i ; j++){
            if(dp[i - j + 1][j])
                temp = dp2[j - 1] + 1;
            if(min == 0 || temp < min)
                min = temp;
        }
        dp2[i] = min;
    }


    cout << dp2[num] << endl;

    return 0;
}
