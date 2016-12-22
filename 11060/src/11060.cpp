//============================================================================
// Name        : 11060.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

int size;
vector<int> arr;

//first -> node second -> count
queue<pair<int, int> > que;
int dp[1001] = {0,};

typedef pair<int, int> input;

int main() {
	scanf("%d", &size);
	arr.push_back(0);
	for(int i = 1 ; i <= size ; i++){
		int temp;
		scanf("%d", &temp);
		arr.push_back(temp);
	}
	que.push(input(1, 0));

	while(true){
		input data = que.front();
		que.pop();

		if(data.first + arr[data.first] >= size){
			printf("%d\n", data.second + 1);
			break;
		}

		for(int jump = 1 ; jump <= arr[data.first] ; jump++){
			if((dp[data.first + jump] == 0) || (dp[data.first + jump] <= data.second + 1)){
				dp[data.first + jump] = data.second + 1;
				input temp(data.first + jump, data.second + 1);
				que.push(temp);
			}
		}

		if(que.empty()){
			printf("%d\n", -1);
			break;
		}
	}


	return 0;
}
