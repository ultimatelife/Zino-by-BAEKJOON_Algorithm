//============================================================================
// Name        : PracticeDijkstra.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[9] = {0,27,10,12,20,25,13,15,22};
int nArr[9] = {0,27,10,12,20,25,13,15,22};

void divide(int arr[]){
}

void merge(int left, int mid, int right){
	int index = left;
	const int cMid = mid;

	while(left != cMid && mid != right){
		int tLeft = arr[left];
		int tRight = arr[mid + 1];

		if(tLeft > tRight){
			nArr[index] = tRight;
		}else{
			nArr[index] = tLeft++;
		}
		index++;
	}
}

void mergeSort(int left, int right){
	int mid = 0;
	if(left < right){
		mid = (right + left) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);
	}

}

int main() {


	return 0;
}
