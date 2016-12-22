//============================================================================
// Name        : 6549.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num;
vector<int> arr;
int mostRec = NULL;

void findMax(int fromIndx, int toIndex) {
	int height = *min_element(&arr.at(fromIndx), &arr.at(toIndex) + 1);
	int value = height * (toIndex - fromIndx + 1);
	if(mostRec == NULL || value > mostRec){
		//printf("from : %d to : %d height : %d value : %d\n", fromIndx, toIndex, height, value);
		mostRec = value;
	}
}

int main() {


	while (true) {
		scanf("%d", &num);
		if(num == 0)
			break;

		arr.clear();
		mostRec = 0;
		for (int i = 0; i < num; i++) {
			int temp;
			scanf("%d", &temp);
			arr.push_back(temp);
		}

		for(int i = 0 ; i < arr.size() ;i++){
			for(int j = i ; j < arr.size() ; j++){
				findMax(i, j);
			}
		}
		printf("%d\n", mostRec);
	}

	return 0;
}
