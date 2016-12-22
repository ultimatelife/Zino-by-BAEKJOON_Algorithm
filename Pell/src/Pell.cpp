#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int len = 0;
int arr[2001];
int qNum = 0;
queue<pair<int, int> > questions;
queue<int> results;

vector<vector<int> > dp;
//int dp[2001][2001] = {{-1,}};

void makeDisable(int x, int y){
	if(dp[x][y] != -1){
		return;
	}

	if(x <= 0 || x > len || y <= 0 || y > len){
		return;
	}
	dp[x][y] = 0;
	makeDisable(x - 1, y + 1);
}

void makeEnable(int x, int y){
	if(dp[x][y] != -1){
		return;
	}

	if(x <= 0 || x > len || y <= 0 || y > len){
		return;
	}

	dp[x][y] = 1;
	makeEnable(x + 1, y - 1);
}

void findP(int x, int y){
	int tx = x, ty = y;
//	printf("x = %d y = %d\n", x, y);

	if(x == y){
//		cout << "s : 0" << endl;
		results.push(1);
		return;
	}

	while(x < y){
		if(dp[x][y] == 0){
//			cout << "s : 1" << endl;
			results.push(0);
			return;
		}

		if (dp[x][y] == 1) {
//			cout << "s : 2" << endl;
			results.push(1);
			return;
		}

		if(arr[x] != arr[y]){
//			cout << "s : 3" << endl;
			makeDisable(x, y);
			results.push(0);
			return;
		}

		x++, y--;
	}

//	cout << "s : 4" << endl;
	makeEnable(tx, ty);
	results.push(1);
}

int main() {
	dp.assign(2001, vector<int>(2001, -1));

	scanf("%d", &len);

	for(int i = 1 ; i <= len ; i++){
		scanf("%d", &arr[i]);
	}

	for(int i = 1 ; i <= len ; i++){
		dp[i][i] = 1;
	}

	scanf("%d", &qNum);
	for(int i = 0 ; i < qNum ; i++){
		int a,b;
		scanf("%d %d", &a, &b);
		questions.push(std::make_pair(a, b));
	}

	while(!questions.empty()){
		int x = questions.front().first, y = questions.front().second;
		questions.pop();
		findP(x, y);
	}

	while(!results.empty()){
		printf("%d\n", results.front());
		results.pop();
	}

	return 0;
}


