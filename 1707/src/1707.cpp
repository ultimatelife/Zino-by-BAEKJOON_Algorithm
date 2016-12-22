//============================================================================
// Name        : 1707.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

int t, nodeNum, edgeNum;
vector<int> edge[20001];
int check[20001];

void dfs(int node, int ch){
    check[node] = ch;
    for(int i = 0 ; i < edge[node].size() ; i++){
        int next = edge[node][i];
        if(check[next] == 0){
            dfs(next, 3 - ch);
        }
    }
}

int main() {
    cin >> t;

    while(t--){
        scanf("%d %d", &nodeNum, &edgeNum);
        for(int i = 1 ; i <= nodeNum ;i++ ){
            edge[i].clear();
            check[i] = 0;
        }

        for(int i = 1 ; i <= edgeNum ;i++ ){
            int a,b;
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        for(int i = 1 ; i <= nodeNum ; i++){
            if(check[i] == 0)
                dfs(i, 1);
        }

        bool result = true;
        for(int i = 1 ; i <= nodeNum ; i++){
            for(int j = 0 ; j < edge[i].size() ; j++){
                if(check[i] == check[edge[i][j]]){
                    result = false;
                    break;
                }
            }
            if(!result)
                break;
        }

        printf("%s\n", result ? "YES" : "NO");
    }

    return 0;
}
