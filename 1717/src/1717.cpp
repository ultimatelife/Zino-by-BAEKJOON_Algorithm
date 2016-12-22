//============================================================================
// Name        : 1717.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int k, a, b;
int arr[1000001] = { 0, };

int find(int x) {
	int temp = x;
	while (x != arr[x]) {
		x = arr[x];
	}
	arr[temp] = x;
	return x;
}

void uni(int x, int y) {
	int xp = find(x);
	int yp = find(y);
	arr[yp] = xp;
}

int main() {
	scanf("%d %d",&n, &m);
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}

	while (m--) {
		scanf("%d %d %d",&k, &a, &b);

		if (k == 0) {
			uni(a, b);
		} else {
			if (find(a) == find(b)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}

	return 0;
}
