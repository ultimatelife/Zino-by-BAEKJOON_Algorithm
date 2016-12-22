//============================================================================
// Name        : Nexon3.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

char cstr[1025];
string str;
int length = 1;

queue<string> save;

int main() {
	scanf("%s", cstr);
	str = cstr;

	for(int i = 0 ; i < str.length(); i++){
		char currentC = str.at(i);
		if(save.empty()){
			save.push(currentC + "");
			continue;
		}

		char beforeC = str.at(i - 1);
		if(beforeC == currentC){
			length++;

			if(i == str.length() - 1)
				save.push(to_string(length));

		}else{
			if(length != 1)
				save.push(to_string(length));
			save.push(currentC + "");
			length = 1;
		}
	}

	while(!save.empty()){
		cout << save.front();
	}
	cout << endl;

	return 0;
}
