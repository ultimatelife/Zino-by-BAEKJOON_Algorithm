//============================================================================
// Name        : TransferTo2.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int from5To10(string str){
	int sum = 0;
	for(int i = 0 ; i < str.length() ; i++){
		sum = sum + (str.at(i) - '0')*((int)pow(5, str.length() - i - 1));
	}
	return sum;
}

int from5to10recur(string str, int cnt){
	if(cnt == str.length() - 1){
		return str.at(cnt) - '0';
	}
	int temp = (str.at(cnt) - '0')*((int)pow(5, str.length() - cnt - 1));
	return temp + from5to10recur(str, cnt + 1);
}

string from10To2(int num){
	if(num == 0){
		return "";
	}
	if(num % 2 == 1){
		return from10To2(num / 2) + "1";
	} else{
		return from10To2(num / 2) + "0";
	}
}

int main() {
	cout << from5To10("111") << endl;
	cout << from5to10recur("111", 0) << endl;
	cout << from10To2(17) << endl;

	return 0;
}
