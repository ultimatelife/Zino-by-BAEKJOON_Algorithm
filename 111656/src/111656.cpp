//============================================================================
// Name        : 111656.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	char cStr[1001];
	string str;
	scanf("%s", cStr);
	str = cStr;

	vector<string> arr;

	for(int i = 0 ; i < str.length() ; i++){
		string temp = str.substr(i, str.length() - i);
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	for(int i = 0 ; i< arr.size() ; i++){
		cout << arr[i] << endl;
	}


	return 0;
}
