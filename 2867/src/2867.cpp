/*
 * 문제
 수열의 값이란 수열에서 가장 큰 원소와 가장 작은 원소의 차이이다.

 예를 들어, (3, 1, 7, 2)는 수열의 값이 6이고, (42, 42)는 0이다.

 수열이 주어졌을 때, 모든 부분 수열의 값의 합을 출력하는 프로그램을 작성하시오 .

 (3, 1, 7, 2)의 부분 수열은 총 10개 (3), (1), (7), (2), (3,1), (1,7), (7,2), (3,1,7), (1,7,2), (3,1,7,2) 가 있고, 각각의 수열의 값을 구한뒤 이를 합하면 31이 된다.
 */
#include <iostream>
#include <stack>
using namespace std;

int num = 0;
int arr[30001] = { 0, };

stack<int> save;

void recurn(int max, int min, int index) {
    if(index > num){
        return;
    }

    if (min == 0 || arr[index] < min)
        min = arr[index];

    if (max == 0 || arr[index] > max)
        max = arr[index];

    save.push(max - min);
    recurn(max, min, index + 1);
}

int main() {
    cin >> num;
    for(int i = 1 ; i <= num ; i++){
        cin >> arr[i];
    }

    for(int i = 1 ; i <= num ; i++)
        recurn(0, 0, i);

    int sum = 0;

    while(!save.empty()){
        sum += save.top();
        save.pop();
    }
    cout << sum << endl;

    return 0;
}
