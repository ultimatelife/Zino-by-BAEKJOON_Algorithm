//============================================================================
// Name        : 3986.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int num;
string str;
int result = 0;

int main() {
	cin >> num;
	char cStr[100001];

	while(num--){
		stack<char> save;
		scanf("%s", cStr);
		str = cStr;

		for(int i = 0 ; i < str.length() ; i++){
			char c = str.at(i);

			if(i == 0){
				save.push(c);
				continue;
			}

			char top = save.top();
			if(top == c){
				save.pop();
			}else{
				save.push(c);
			}
		}

		if(save.empty()){
			result++;
		}
	}

	cout << result << endl;

	return 0;
}
