#include <iostream>
#include <vector>
#include <algorithm>

class Info{
public:
    int node;
    int cost;

    Info(int n, int c){
        node = n;
        cost = c;
    }
};

using namespace std;

int V, E, startNode, INF = 11;
vector<Info> edge[200001];
int check[200001][200001];
int cost[200001][200001];

int findNode(int from, int to){
    if (from == to)
        return 0;

    if (cost[from][to] != INF)
        return cost[from][to];


    int result = INF;
    for (int i = 0 ; i < edge[from].size(); i++) {
        int u = edge[from][i].node;
        if (check[u][to] != 1) {
            check[u][to] = 1;
            int next_cost = edge[from][i].cost + findNode(u, to);
            result = min(result, next_cost);
            check[u][to] = 0;
        }
    }

    if (result < cost[to][from] ) {
        cost[to][from] = result;
        cost[from][to] = result;
    }
    return result;
}

int main() {
    scanf("%d %d %d", &V, &E, &startNode);

    for(int i = 1 ; i <= E; i++){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back(Info(b, c));
        edge[b].push_back(Info(a, c));
    }

    findNode(1, 4);

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            printf("%d ", cost[i][j]);
        }
        puts("");
    }

    return 0;
}
