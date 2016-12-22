/*
 문제
 N개의 수로 된 수열 A[1], A[2], …, A[N] 이 있다. 이 수열의 i번째 수부터 j번째 수까지의 합 A[i]+A[i+1]+…+A[j-1]+A[j]가 M이 되는 경우의 수를 구하는 프로그램을 작성하시오.

 입력
 첫째 줄에 N(1≤N≤10,000), M(1≤M≤300,000,000)이 주어진다. 다음 줄에는 A[1], A[2], …, A[N]이 공백으로 분리되어 주어진다. 각각의 A[x]는 30,000을 넘지 않는 자연수이다.

 출력
 첫째 줄에 경우의 수를 출력한다.

 예제 입력  복사
 4 2
 1 1 1 1
 예제 출력  복사
 3
 예제 입력 2  복사
 10 5
 1 2 3 4 2 5 3 1 1 2
 예제 출력 2  복사
 3
 */
#include <iostream>
#include <vector>

using namespace std;

int n, m, maxCnt =0;
vector<int> arr;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
        if(x == m)
            maxCnt++;
    }

    for (int i = 0; i < n; i++) {
        int temp = arr[i];
        for (int j = i + 1; j < n; j++) {
            temp = temp + arr[j];
            if(temp == m){
                maxCnt++;
                break;
            }

            if(temp > m){
                break;
            }
        }
    }

    cout << maxCnt << endl;

    return 0;
}