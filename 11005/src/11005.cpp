/*
문제
10진법 수 N이 주어진다. 이 수를 B진법으로 바꿔 출력하는 프로그램을 작성하시오.

10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다. 이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.

A: 10, B: 11, ..., F: 16, ..., Y: 34, Z: 35

입력
첫째 줄에 N과 B가 주어진다. (2 ≤ B ≤ 36) N은 10억보다 작거나 같은 자연수이다.

출력
첫째 줄에 10진법 수 N을 B진법으로 출력한다.

예제 입력  복사
60466175 36
예제 출력  복사
ZZZZZ
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n, b;
int result;
stack<char> arr;

char translateFromIntegerToString(int x) {
    if (x >= 10) {
        return 'A' + x - 10;
    } else {
        return x + '0';
    }
}

void convert(int n, int b) {
    while (n >= b) {
        char rest = translateFromIntegerToString(n % b);
        n /= b;
        arr.push(rest);
    }
    arr.push(translateFromIntegerToString(n));

    while (!arr.empty()) {
        cout << arr.top();
        arr.pop();
    }
    puts("");
}

int main() {
    cin >> n >> b;
    convert(n, b);
    return 0;
}
