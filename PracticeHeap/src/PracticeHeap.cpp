//============================================================================
// Name        : PracticeHeap.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;
/*
 * stl queue 구현 방법
 * priority_queue<int, vector<int>, greater<int>> q;
 * 작은 것부터 나옴
 *
 * priority_queue<int, vector<int>, less<int>> q;
 * 큰것 부터 나옴
 */

int tail = 1;
int maxHeap[100001] = { 0, };

void maxHeapHeapInsert(int n, int currentIndex) {
	if (currentIndex == tail) {
		tail++;
	}
	maxHeap[currentIndex] = n;

	int parentIndex = currentIndex / 2;
	int parentValue = maxHeap[parentIndex];

	if (parentValue < n) {
		int temp = parentValue;
		maxHeap[parentIndex] = n;
		maxHeap[currentIndex] = temp;
		maxHeapHeapInsert(n, parentIndex);
	}
}

void maxHeapInsertTest() {
	maxHeapHeapInsert(7, tail), maxHeapHeapInsert(8, tail), maxHeapHeapInsert(9,
			tail);

	printf("print : ");
	for (int i = 1; i < tail; i++) {
		cout << maxHeap[i] << " ";
	}
	maxHeapHeapInsert(6, tail);

	printf("print : ");
	for (int i = 1; i < tail; i++) {
		cout << maxHeap[i] << " ";
	}
	cout << endl;
}

void maxHeapDelete(int index) {
	if (index == 1)
		maxHeap[index] = maxHeap[tail--];

	int left, right;
	int leftIndex = index * 2;
	int rightIndex = index * 2 + 1;
	if (maxHeap[index * 2] != 0) {
		left = maxHeap[leftIndex];
	}

	if (maxHeap[index * 2 + 1] != 0) {
		right = maxHeap[rightIndex];
	}

	int temp, tempIndex;
	if (left < right) {
		temp = right;
		tempIndex = rightIndex;
	} else {
		temp = left;
		tempIndex = leftIndex;
	}

	int temp2 = temp;

}

int main() {

	return 0;
}
