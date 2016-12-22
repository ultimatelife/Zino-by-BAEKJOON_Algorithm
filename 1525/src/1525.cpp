//============================================================================
// Name        : 1963.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

const int result = 123456789;
map<int, int> check;
int dirRow[4] = {0,0,-1,1};
int dirCol[4] = {-1,1,0,0};


int main() {
    int start = 0;
    for(int i  = 0 ; i < 3;  i++){
        for(int j  = 0 ; j < 3;  j++){
            int x;
            cin >> x;
            if(x == 0){
                x = 9;
            }
            start = start * 10 + x;
        }
    }

    queue<int> qu;
    qu.push(start);
    check[start] = 0;


    while(!qu.empty()){
        int x = qu.front();
        string xStr = to_string(x);
        qu.pop();
        if(x == 123456789)
            break;

        string tx = to_string(x);
        int index = tx.find('9');
        int row = index / 3;
        int col = index % 3;

        for(int i = 0 ; i < 4 ; i++){
            int nextRow = row + dirRow[i];
            int nextCol = col + dirCol[i];

            if(nextRow >= 0 && nextRow < 3 && nextCol >= 0 && nextCol < 3){
                string temp = xStr;
                int nextIndex = nextRow *3 + nextCol;
                swap(temp[index], temp[nextIndex]);
                int saveIndex = stoi(temp);

                if(check.count(saveIndex) == 0){
                    check[saveIndex] = check[x] + 1;
                    qu.push(saveIndex);
                }
            }
        }
    }

    if(check.count(result) == 0){
        cout << -1 << endl;
    }else{
        cout << check[result] << endl;
    }

    return 0;
}
