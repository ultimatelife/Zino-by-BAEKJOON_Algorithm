//============================================================================
// Name        : 2146.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<int, int>> qu;
queue<pair<int, int>> rqu;

typedef pair<int, int> pa;

int num, length = 1;
int arr[101][101];
int check[101][101];
int varr[101][101];

int dirRow[4] = { 0, 0, -1, 1 };
int dirCol[4] = { -1, 1, 0, 0 };

void bfs(int row, int col) {
    //밑에 for 문에다가 cnt 증가
    check[row][col] = length;
    qu.push(pa(row, col));

    while (!qu.empty()) {
        pa p = qu.front();
        qu.pop();
        int cRow = p.first;
        int cCol = p.second;

        for (int i = 0; i < 4; i++) {
            int nextRow = cRow + dirRow[i];
            int nextCol = cCol + dirCol[i];

            if (nextRow < 1 && nextCol < 1 && nextRow > num && nextCol > num)
                continue;

            if(arr[nextRow][nextCol] != 0 && check[nextRow][nextCol] == 0){
                check[nextRow][nextCol] = length;
                qu.push(pa(nextRow, nextCol));
            }else if(arr[nextRow][nextCol] == 0 && check[nextRow][nextCol] == 0){
                rqu.push(pa(nextRow, nextCol));
                check[nextRow][nextCol] = length;
                varr[nextRow][nextCol] = 1;
            }

        }
    }
}

int main() {
    cin >> num;
    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num; j++) {
            if (!check[i][j] && !arr[i][j]) {
                bfs(i, j);
                length++;
            }
        }
    }

    bool out = true;
    int result = 0;
    while(!rqu.empty() && out){
        pa temp = rqu.front();
        rqu.pop();
        int row = temp.first;
        int col = temp.second;

        for(int i = 0 ; i < 4 ; i++){
            int nRow = row + dirRow[i];
            int nCol = col + dirCol[i];

            if(check[nRow][nCol] == 0){
                rqu.push(pa(nRow, nCol));
                check[nRow][nCol] = check[row][col];
                varr[nRow][nCol] = varr[row][col] + 1;
            } else if(check[nRow][nCol] != check[row][col]){
                result = check[nRow][nCol] + check[row][col];
                out = false;
            }
        }
    }
    cout << result << endl;

    return 0;
}
