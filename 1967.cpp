#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;

int maxNode = 0, maxNodeValue = 0;
int num, result = 0;
vector<P> edge[10001];

void findMaxNodeDFS(int node, int beforeNode, int sum){
    if (edge[node].size() == 1 && node != beforeNode) {
        if (maxNodeValue < sum) {
            maxNode = node;
            maxNodeValue = sum;
        }
    }
    
    for(auto a : edge[node]){
        if (a.first != beforeNode) {
            findMaxNodeDFS(a.first, node, sum + a.second);
        }
    }
}

int main() {
    cin >> num;
    for (int i = 1; i <= num - 1; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
        edge[b].push_back(make_pair(a, c));
    }
    findMaxNodeDFS(1, 1, 0);
//    printf("maxNode : %d    maxNodeValue : %d\n", maxNode, maxNodeValue);
    
    maxNodeValue = 0;
    findMaxNodeDFS(maxNode, maxNode, 0);
    printf("%d\n", maxNodeValue);
    
    return 0;
}
