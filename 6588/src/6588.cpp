//============================================================================
// Name        : 6588.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num;
int prim[1000001];
vector<int> arrPrim;


int main() {
	fill(&prim[0], &prim[1000001] + 1, -1);
	for(int i = 2 ; i <= 1000000 ; i++){
		if(prim[i] == 0)
			continue;

		arrPrim.push_back(i);
		for(int j = i + i ; j <= 1000000 ; j = j + i){
			prim[j] = false;
		}
	}

	while(true){
		cin >> num;
		if(num== 0)
			break;


	}



	return 0;
}
