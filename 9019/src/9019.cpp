//============================================================================
// Name        : 1963.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    int t, from, to;
    cin >> t;


    while(t--){
        cin >> from >> to;
        int check[10000];
        char save[10000];
        fill(&check[0], &check[10000] + 1, -1);

        queue<int> qu;
        qu.push(from);
        check[from] = 0;
        save[from] = ' ';

        while(!qu.empty()){
            int x = qu.front();
            //printf("x : %d\n", x);
            qu.pop();
            if(x == to){
                break;
            }

            //1
            int next1 = x * 2;
            if(next1 > 9999){
                next1 %= 10000;
            }
            if(next1 >= 0 && next1 < 10000 && check[next1] == -1){
                check[next1] = x;
                save[next1] = 'D';
                qu.push(next1);
            }

            //2
            int next2 = x - 1;
            if(next2 == -1) next2 = 9999;
            if(next2 >= 0 && next2 < 10000 && check[next2] == -1){
                check[next2] = x;
                save[next2] = 'S';
                qu.push(next2);
            }

            //3
            int next3 = x % 1000 * 10 + x / 1000;
            if(next3 >= 0 && next3 < 10000 && check[next3] == -1){
                check[next3] = x;
                save[next3] = 'L';
                qu.push(next3);
            }

            //4
            int next4 = x % 10 * 1000 + x / 10;
            if(next4 >= 0 && next4 < 10000 && check[next4] == -1){
                check[next4] = x;
                save[next4] = 'R';
                qu.push(next4);
            }
        }

        int index = to;
        string str =  "";
        while(index != from){
            str = save[index] + str;
            index = check[index];
        }
        cout << str << endl;
    }

    return 0;
}
