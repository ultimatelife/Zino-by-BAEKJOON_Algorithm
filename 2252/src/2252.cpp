//============================================================================
// Name        : 2252.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> edge[32001];
int numOfEdgeofNode[32001];
int check[32001];
int n,m;

int main() {
    cin >> n >> m;
    for(int i =1 ; i<= m ; i++){
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        numOfEdgeofNode[b]++;
    }

    queue<int> qu;
    for(int i = 1 ; i <= n ; i++){
        if(numOfEdgeofNode[i] == 0){
            qu.push(i);
        }
    }

    while(!qu.empty()){
        int node = qu.front();
        qu.pop();
        printf("%d ", node);

        for(int i = 0 ; i < edge[node].size() ; i++){
            int next = edge[node][i];
            numOfEdgeofNode[next]--;

            if(numOfEdgeofNode[next] == 0){
                qu.push(next);
            }
        }
    }
    cout << endl;
    return 0;
}
