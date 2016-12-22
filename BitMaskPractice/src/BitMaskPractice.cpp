//============================================================================
// Name        : BitMaskPractice.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>

using namespace std;

int main() {
	bitset<8> bit;
	bit.set();
	for(int i = 0  ; i < bit.size() ; i++){
		cout << bit << " ";
	}
	puts("");


	return 0;
}
