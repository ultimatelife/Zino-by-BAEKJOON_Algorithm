//============================================================================
// Name        : 1916.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node{
	int cose;
	int node;

	bool operator < (const Node &o) const{
		return cose > o.cose;
	}

};

int main() {
	Node node1 = {1, 2};
	Node node2 = {2, 2};
	Node node3 = {3, 2};
	Node node4 = {4, 2};
	Node node5 = {4, 2};
	Node node6 = node1;

	priority_queue<Node> qu;
	qu.push(node1);
	qu.push(node2);
	qu.push(node3);
	qu.push(node4);
	qu.push(node5);
	while(!qu.empty()){
		cout << qu.top().cose <<  " " << qu.top().node << endl;
		qu.pop();
	}
	node1.cose = 100;
	cout << "node6 " << node6.cose << endl;

	return 0;
}
