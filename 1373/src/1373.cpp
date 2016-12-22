#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[2][2][2];

int main() {
    arr[0][0][0] = 0;
    arr[0][0][1] = 1;
    arr[0][1][0] = 2;
    arr[0][1][1] = 3;
    arr[1][0][0] = 4;
    arr[1][0][1] = 5;
    arr[1][1][0] = 6;
    arr[1][1][1] = 7;

    string num;
    cin >> num;
    int rest = num.length() % 3;

    if(rest == 1){
        num = "0" + num;
        num = "0" + num;
    }else if(rest == 2){
        num = "0" + num;
    }

    int length = num.length();

    queue<int> qu;
    for(int i = 0 ; i < length ; i = i + 3){
        string str = num.substr(i,3);
        qu.push(arr[str.at(0) - '0'][str.at(1) - '0'][str.at(2) - '0']);
    }

    while(!qu.empty()){
        cout << qu.front();
        qu.pop();
    }
    puts("");


    return 0;
}
