//============================================================================
// Name        : PracticeMap.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
using namespace std;

int main() {
	map<string, int> tMap;

	tMap.insert(pair<string, int>("show", 1));
	cout << tMap.begin() ->first << endl;
	cout << tMap.find("show")->second << endl;

	cout << tMap["show"] << endl;

	return 0;
}
