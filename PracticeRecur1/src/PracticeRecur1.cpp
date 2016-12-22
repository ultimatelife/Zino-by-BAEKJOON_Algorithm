//============================================================================
// Name        : PracticeRecur1.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

queue<string> results;

int testcase;
char cstr[100001] ={};
bool check[100001] ={0,};
int length=0;
string str;


void findResult(int index, int cnt, string ss){
	if(check[index])
		return;

	if(cnt == length){
		cout << str.at(index) << endl;
		return;
	}

	check[index] = true;
	for(int i = 0 ; i < length ; i++){

	}
	check[index] = false;
}

int main() {
	cin >> testcase;

	while(testcase--){
		scanf("%s", cstr);
		str = cstr;
		length = str.length();

		for(int i = 0 ; i< length ; i++){
			findResult(i, 1);
		}
	}



    return 0;
}
