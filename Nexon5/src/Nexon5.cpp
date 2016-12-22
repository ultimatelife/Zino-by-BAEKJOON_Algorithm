//============================================================================
// Name        : Nexon5.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int n1, n2, n3, n4;
bool check = false;

void dfs(int x, int y){
    if(check)
        return;

    if(x == n3 && y == n4){
        check = true;
        return;
    }
    if (x > n3 || y > n4) {
        return;
    }
    dfs(x + y, y);
    dfs(x, x + y);
}

int main() {
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
    dfs(n1, n2);
    cout << check << endl;

    return 0;
}
