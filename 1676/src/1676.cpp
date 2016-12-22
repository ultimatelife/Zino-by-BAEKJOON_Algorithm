/*
문제
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

출력
첫째 줄에 구한 0의 개수를 출력한다.

예제 입력  복사
10
예제 출력  복사
2
 */
#include <iostream>
using namespace std;

int num,cnt = 0;
int main() {
	cin >> num;
	for(int i = 5 ; i<= num ; i = i + 5){
		int temp = i;
		while(temp % 5 == 0){
			temp /= 5;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
