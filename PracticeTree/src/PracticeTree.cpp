//============================================================================
// Name        : PracticeTree.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Tree {
public:
	int data;
	Tree* left;
	Tree* right;

	Tree(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}

	void insertNode(Tree *tr) {
		if (tr->data < data) {
			if (left == NULL) {
				printf("%d 가 추가되었습니다.\n", tr->data);
				setLeft(tr);
			} else {
				left->insertNode(tr);
			}
		} else {
			if (right == NULL) {
				printf("%d 가 추가되었습니다.\n", tr->data);
				setRight(tr);
			} else {
				right->insertNode(tr);
			}
		}
	}

	Tree* findNode(int d) {
		printf("%d 를 탐색중이다.\n", data);

		if (data == d) {
			return this;
		} else {
			if (d < data) {
				if (left == NULL) {
					printf("%d 를 찾을수 없다.\n", d);
					return NULL;
				} else {
					return left->findNode(d);
				}
			} else {
				if (right == NULL) {
					printf("%d 를 찾을수 없다.\n", d);
					return NULL;
				} else {
					return right->findNode(d);
				}
			}
		}
	}

	void deleteNode(int data){
		Tree *dNode = findNode(data);
		Tree* parentLeft = this->parentOfMostLeft(this);
		Tree* mostLeft = parentLeft->left;

		Tree* parentRight = this->parentOfMostRight(this);
		Tree* mostRight = parentRight->right;

		int lv = data - mostLeft->data;
		int rv = data - mostRight->data;

		if(lv < rv){
			parentLeft->left = NULL;

		} else{

		}
	}

	Tree* parentOfMostRight(Tree *tr){
		if(tr->right->right == NULL){
			//맨 오른쪽 노드의 위쪽을 리턴
			return tr;
		}else{
			return parentOfMostRight(tr->right);
		}
	}

	Tree* parentOfMostLeft(Tree *tr){
		if(tr->left->left == NULL){
			//맨 왼쪽 노드의 위쪽을 리턴
			return tr;
		}else{
			return parentOfMostLeft(tr->left);
		}
	}

	void setLeft(Tree *l) {
		left = l;
	}
	void setRight(Tree *r) {
		right = r;
	}
};

int main() {
	Tree head(35);
	Tree t1(18), t2(68), t3(7), t4(26), t5(99), t6(3), t7(12), t8(22), t9(30);
	head.insertNode(&t1);
	head.insertNode(&t2);
	head.insertNode(&t3);
	head.insertNode(&t4);
	head.insertNode(&t5);
	head.insertNode(&t6);
	head.insertNode(&t7);
	head.insertNode(&t8);
	head.insertNode(&t9);


	head.findNode(7);
	cout << head.parentOfMostLeft(&t1)->data << endl;
	cout << head.parentOfMostRight(&t1)->data << endl;

	//head.findNode(4);

	return 0;
}
