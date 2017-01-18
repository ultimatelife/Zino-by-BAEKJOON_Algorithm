#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 8765432;
int V,E,K;
vector<pair<int, int>> edge[20001];
priority_queue<pair<int, int>> qu;
int check[20001];
//int path[20001];

int main() {
    scanf("%d %d", &V, &E);
    scanf("%d", &K);

    fill(&check[0], &check[V] + 1, INF);

    for (int i = 1 ; i <= E; i++) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back(make_pair(b, c));
    }

    qu.push(make_pair(K, 0));
    check[K] = 0;
    while (!qu.empty()) {
        int node = qu.top().first;
        int cost = qu.top().second;
        qu.pop();

        if (check[node] < cost)
            continue;

        for (int i = 0 ; i < edge[node].size(); i++) {
            int next_node = edge[node][i].first;
            int next_cost = edge[node][i].second;

            if (check[next_node] > next_cost + cost) {
                qu.push(make_pair(next_node, next_cost + cost));
                check[next_node] = next_cost + cost;
            }
        }
    }

    for (int i = 1 ; i <= V; i++) {
        if (check[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", check[i]);
    }


    return 0;
}
