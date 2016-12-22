//============================================================================
// Name        : 11724.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>

using namespace std;

int result = 0, n, m;

vector<int> edge[1001];
bool check[1001];

bool dfs(int node, int cnt) {
	if (check[node] && cnt == 0)
		return false;

	check[node] = true;

	for (int i = 0; i < edge[node].size(); i++) {
		int cNode = edge[node][i];
		if (!check[cNode]) {
			dfs(cNode, cnt + 1);
		}
	}
	return true;
}

bool bfs(int node) {
	if (check[node])
		return false;

	queue<int> qu;
	qu.push(node);
	check[node] = true;

	while (!qu.empty()) {
		node = qu.front();
		qu.pop();

		for (int i = 0; i < edge[node].size(); i++) {
			int cNode = edge[node][i];
			if (!check[cNode]) {
				check[cNode] = true;
				qu.push(cNode);
			}
		}
	}
	return true;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	/*dfs
	 for(int i = 1 ; i <= n ; i++){
	 if(dfs(i, 0))
	 result++;
	 }
	 cout << result << endl;
	 */

	//bfs
	for (int i = 1; i <= n; i++) {
		if (bfs(i))
			result++;
	}
	cout << result << endl;

	return 0;
}
