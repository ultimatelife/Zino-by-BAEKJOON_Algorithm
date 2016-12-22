//============================================================================
// Name        : 2580.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <vector>
#include <bitset>

using namespace std;

int arr[10][10] = { { 0, }, };
queue<pair<int, int> > zerop;

int checkRow(int r, int c) {
	int result = 0;
	bitset<9> bit;
	bitset<9> com;
	com.set();
	bit.set();

	for (int i = 1; i <= 9; i++) {
		int temp = arr[i][c];
		bit.set(temp, false);
	}
	int cnt = 9 - bit.count();
	if (cnt == 1) {
		bit = bit & com;
		string s = bit.to_string();
		int result = bit.size() - s.find('1');
		return result;
	}
	return result;
}

int checkCol(int r, int c) {
	int result = 0;
	bitset<9> bit;
	com.set();

	for (int i = 1; i <= 9; i++) {
		int temp = arr[r][i];
		bit.set(temp, false);
	}
	int cnt = 9 - bit.count();
	if (cnt == 1) {
		bit = bit & com;
		string s = bit.to_string();
		int result = bit.size() - s.find('1');
		return result + 1;
	}
	return result;
}

int checkRectangle(int r, int c) {
	int result = 0;
	int rVal = r / 3;
	int rRest = r % 3;
	int cVal = c / 3;
	int cRest = c % 3;

	int startRow = rVal * 3 + rRest;
	int startCol = cVal * 3 + cRest;

	bitset<9> bit;
	bit.set();

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int currentRow = startRow + i;
			int currentCol = startCol + j;
			int temp = arr[currentRow][currentCol];
			bit.set(temp, false);
		}
	}

	if (bit.count() == 1) {
		string s = bit.to_string();
		int result = bit.size() - s.find('1');
		return result;
	}
	return result;
}

int main() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				zerop.push(make_pair(i, j));
		}
	}

	while (!zerop.empty()) {
		pair<int, int> temp = zerop.front();
		zerop.pop();

		int value = checkRow(temp.first, temp.second);
		if (value != 0) {
			arr[temp.first][temp.second] = value;
			continue;
		}

		value = checkCol(temp.first, temp.second);
		if (value != 0) {
			arr[temp.first][temp.second] = value;
			continue;
		}

		value = checkRectangle(temp.first, temp.second);
		if (value != 0) {
			arr[temp.first][temp.second] = value;
			continue;
		}

		if (value == 0)
			zerop.push(make_pair(temp.first, temp.second));
	}

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << arr[i][j] << " ";
		}
		puts("");
	}

	return 0;
}
