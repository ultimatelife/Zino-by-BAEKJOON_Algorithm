/*
문제
-2진법은 부호 없는 2진수로 표현이 된다. 2진법에서는 20, 21, 22, 23이 표현 되지만 -2진법에서는 (-2)0 = 1, (-2)1 = -2, (-2)2 = 4, (-2)3 = -8을 표현한다. 10진수로 1부터 표현하자면 1, 110, 111, 100, 101, 11010, 11011, 11000, 11001 등이다.

10진법의 수를 입력 받아서 -2진수를 출력하는 프로그램을 작성하시오.

입력
첫 줄에 10진법으로 표현된 수 N(-2,000,000,000≤N≤2,000,000,000)이 주어진다.

출력
-2진법 수를 출력한다.

예제 입력  복사
-13
예제 출력  복사
110111

 */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long num,length = 0;
int arr[1000000];
bool found = false;

void recur(int cnt, long long sum){
	if(!found)
		return;

	if(sum == num){
		for(int i = 1 ; i <= length; i++){
			cout << arr[i];
		}
		puts("");
		return;
	}

	arr[cnt] = 1;

}

int main() {
	cin >> num;
	if(num == 0){
		cout << 0 << endl;
		return 0;
	}

	long long sum = 0;
	if(num < 0){
		while(true){
			if(length % 2 == 0){
				length++;
				continue;
			}
			if(-num < sum)
				break;
			sum += pow(2, length);
		}
	}else{
		while(true){
			if(length % 2 == 1){
				length++;
				continue;
			}
			if(num < sum)
				break;
			sum += pow(2, length);
		}
	}


	return 0;
}
