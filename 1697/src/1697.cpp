
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int check[100001] = {0,};
queue<int> qu;
int old,young;

int main() {
    cin >> old >> young;
    fill(&check[0], &check[100001] + 1, -1);
    check[old] = 0;
    qu.push(old);


    while(!qu.empty()){
        int x = qu.front();
        qu.pop();
        if(x == young){
            break;
        }


        int next0 = x - 1;
        if(next0 >= 0 && check[next0] == -1){
            check[next0] = check[x] + 1;
            qu.push(next0);
        }


        int next1 = x + 1;
        if(next1 <= 100000 && check[next1] == -1){
            check[next1] = check[x] + 1;
            qu.push(next1);
        }


        int next2 = x*2;
        if(next2 <= 100000 && check[next2] == -1){
            check[next2] = check[x] + 1;
            qu.push(next2);
        }

    }
    cout << check[young] << endl;

    return 0;
}
