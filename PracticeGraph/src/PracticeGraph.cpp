//============================================================================
// Name        : PracticeGraph.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node {
public:
	int id = 0;
	int weight = 0;
	Node *next = NULL;

	Node(int _id, Node *_next) {
		id = _id;
		next = _next;
	}

	Node(int _id, Node *_next, int _weight) {
		id = _id;
		next = _next;
		weight = _weight;
	}

	Node(int _id) {
		id = _id;
	}

	Node() {
	}
};

class Graph {
public:
	int size;
	Node *nodes[10001];

	void addNode(int id, int value) {
		size++;
	}

	//Nondirection
	void addEdge(int id1, int id2) {
		Node *id2Node, *id1Node;
		id2Node = (Node*)malloc(sizeof(Node));
		id2Node->next = nodes[id1];
		nodes[id1] = id2Node;

		id1Node = (Node*)malloc(sizeof(Node));
		id1Node->next = nodes[id2];
		nodes[id2] = id1Node;
	}
};

int main() {

	return 0;
}
