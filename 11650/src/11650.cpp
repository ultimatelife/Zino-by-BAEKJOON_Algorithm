//============================================================================
// Name        : 11650.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int ,int > a, pair<int ,int > b){
	if(a.first > b.first){
        return true;
    }else if(a.first == b.first){
        if(a.second > b.second){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

int main() {
    vector<pair<int, int> > arr;
    int num;
    cin >> num;

    for(int i = 1 ; i <= num ; i++){
        int a,b;
        cin >> a >> b;
        arr.push_back(make_pair(a,b));

    }
    sort(arr.begin(), arr.end());

    for(int i = 0 ; i < arr.size() ; i++){
        printf("%d %d\n", arr[i].first, arr[i].second, greater<int>);
    }

    return 0;
}
