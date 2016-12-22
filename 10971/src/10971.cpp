/*
 입력
 첫째 줄에 도시의 수 N이 주어진다. (2<=N<=10) 다음 N개의 줄에는 비용 행렬이 주어진다. 각 행렬의 성분은 1,000,000 이하의 양의 정수이며, 갈 수 없는 경우는 0이 주어진다. W[i][j]는 도시 i에서 j로 가기 위한 비용을 나타낸다.

 항상 순회할 수 있는 경우만 입력으로 주어진다.

 출력
 첫째 줄에 외판원의 순회에 필요한 최소 비용을 출력한다.

 예제 입력  복사
 4
 0 10 15 20
 5  0  9 10
 6 13  0 12
 8  8  9  0
 예제 출력  복사
 35
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num;
int arr[11][11];

int mininum = 0;

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
		}
	}
	vector<int> dir;
	for (int i = 0; i < num; i++) {
		dir.push_back(i);
//		dir[i] = i;
	}

	do {
		bool check = true;
		int sum = 0;
		for (int i = 0; i < num - 1; i++) {
			int from = dir[i];
			int to = dir[i + 1];

			if (arr[from][to] != 0) {
				sum += arr[from][to];
			} else {
				check = false;
				break;
			}
		}
		int from = dir[num];
		int to = dir[0];

		if(arr[from][to] != 0){
			sum += arr[from][to];
		}else{
			check = false;
			continue;
		}

		if (check && (mininum == 0 || mininum > sum)) {
			mininum = sum;
		}
	} while (next_permutation(dir.begin(), dir.end()));
	cout << mininum << endl;

	return 0;
}
