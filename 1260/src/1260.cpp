//============================================================================
// Name        : 1260.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int nodeNum;
int edgeNum;
int startNode;

vector<vector<int>> edge;

bool checkSt[1001];

queue<int> qu;
bool checkQu[1001];

queue<int> saveDfs;
queue<int> saveBfs;

void dfs(int node) {
    saveDfs.push(node);
    checkSt[node] = true;

    for(int i = 0 ; i < edge[node].size() ; i++){
    	if(!checkSt[i]){
    		dfs(edge[node][i]);
    	}
    }

}

void bfs(int node) {
    qu.push(node);
    checkQu[node] = true;

    while (!qu.empty()) {
        int temp = qu.front();
        qu.pop();
        saveBfs.push(temp);

        for(int i = 0 ; i < edge[temp].size() ; i++){
			std::__1::__vector_base::value_type currentNode = edge[temp][i];
			if (!checkQu[currentNode]) {
        		qu.push(edge[temp].size());
        		checkQu(edge[temp][i]);
        	}
        }
    }
}

int main() {
    scanf("%d %d %d", &nodeNum, &edgeNum, &startNode);
    edge.assign(nodeNum + 1, vector<int>(nodeNum + 1, 0));

    int a, b;
    for (int i = 1; i <= nodeNum; i++) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(startNode);
    bfs(startNode);

    while (!saveDfs.empty()) {
        printf("%d ", saveDfs.front());
        saveDfs.pop();
    }

    cout << endl;
    while (!saveBfs.empty()) {
        printf("%d ", saveBfs.front());
        saveBfs.pop();
    }

    return 0;
}
