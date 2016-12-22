/*
 *
 */
#include <iostream>
#include <stack>
using namespace std;

char cPattern[26];
char cStr[300001];

string pattern;
string str;

stack<char> indexs;

int main() {
	scanf("%s %s", cPattern, cStr);
	pattern = cPattern, str = cStr;
	bool check = true;

	for(int i = 0 ; i <= str.length() - str.length() ; i++){
		for(int j = 0 ;  j < pattern.length() ; j++){
			int index = i + j;

			if(str.at(index) != pattern.at(j)){
				check = false;
				break;
			}
		}

		if(!check){
			indexs.push(str.at(i));
		}else{
			i = i + pattern.length();
		}
	}
	
	while(indexs.empty()){
		cout << indexs.top();
		indexs.pop();
	}
	cout << endl;

	return 0;
}
