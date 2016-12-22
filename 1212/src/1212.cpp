//============================================================================
// Name        : 1212.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main() {
    string num;
    string arr[8];
    cin >> num;
    arr[0] = "000";
    arr[1] = "001";
    arr[2] = "010";
    arr[3] = "011";
    arr[4] = "100";
    arr[5] = "101";
    arr[6] = "110";
    arr[7] = "111";

    int length = num.length();
    queue<string> qu;

    bool check = true;
    for(int i = 0 ; i < length ; i++){
        int index = num.at(i) - '0';
        string str = arr[num.at(i) - '0'];
        if(check){
            check = false;
            if(index == 1){
                cout << "1";
            }else if(index == 2){
                cout << "10";
            }else if(index == 3){
                cout << "11";
            }else{
                cout << arr[index];
            }
        }else{
            cout << str;
        }
    }
    puts("");
    return 0;
}
