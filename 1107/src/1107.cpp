/*
 문제
 수빈이는 TV를 보고 있다. 수빈이는 채널을 돌리려고 했지만, 버튼을 너무 세게 누르는 바람에, 일부 숫자 버튼을 망가뜨렸다.

 리모컨에는 버튼이 0부터 9까지 숫자, +와 -가 있다. +를 누르면 현재 보고있는 채널에서 +1된 채널로 이동하고, -를 누르면 -1된 채널로 이동한다. 채널 0에서 -를 누른 경우에는 채널이 변하지 않고, 채널은 무한대 만큼 있다.

 수빈이가 지금 이동하려고 하는 채널은 N이다. 어떤 버튼이 망가져있는지 주어졌을 때, N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오.

 수빈이가 지금 보고 있는 채널은 100번이다.

 입력
 첫째 줄에 수빈이가 이동하려고 하는 채널 N (0 ≤ N ≤ 500,000)이 주어진다.  둘째 줄에는 망가진 버튼의 개수 M (0 ≤ M ≤ 10)이 주어진다. 셋째 줄에는 망가진 버튼이 주어지며, 같은 버튼이 중복되서 주어지는 경우는 없다.

 출력
 첫째 줄에 N으로 이동하기 위해 버튼을 최소 몇 번 눌러야 하는지를 출력한다.

 예제 입력  복사
 5457
 3
 6 7 8
 예제 출력  복사
 6
 예제 입력 2  복사
 100
 5
 0 1 2 3 4
 예제 출력 2  복사
 0
 예제 입력 3  복사
 500000
 8
 0 2 3 4 6 7 8 9
 예제 출력 3  복사
 11117
 */
#include <iostream>
#include <cmath>

using namespace std;

bool notNums[10];

long long num, cmin = 0, length, nn, click = 0;

void recur(long long sum, long long cnt) {
	int temp = abs(num - sum) + cnt;
	//printf("sum : %d temp : %d\n", sum, temp);

	if (sum > 50000000)
		return;

	if (cmin == 0 || temp < cmin) {
		cmin = temp;
	}

	for (int i = 0; i < 10; i++) {
		if (notNums[i]) {
			if (sum == 0 && i == 0)
				continue;
			recur(sum * 10 + i, cnt + 1);
		}
	}
}

int main() {
	cin >> num;
	cin >> nn;

	if (100 == num) {
		cout << 0 << endl;
	} else {
		cmin = abs(num - 100);
		fill(&notNums[0], &notNums[10] + 1, true);
		for (int i = 0; i < nn; i++) {
			int x;
			cin >> x;
			notNums[x] = false;
		}
		length = 10 - nn;
		recur(0, 0);
		cout << cmin << endl;
	}

	return 0;
}
