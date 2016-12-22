//============================================================================
// Name        : 1158.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[500001] = { 0, };
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	long long result = 0;
	stack<int> st;
	for (int i = 1; i <= n; i++) {
		int cHeight = arr[i];
		if (st.empty()) {
			st.push(cHeight);
			continue;
		}

		if (st.top() <= cHeight) {
			while (!st.empty() && st.top() < cHeight) {
				result++;
				st.pop();
			}

			int cnt = 0;
			if(!st.empty() && st.top() == cHeight){
				while(!st.empty() && st.top() == cHeight){
					st.pop();
					cnt++;
					result++;
				}
//				printf("cnt : %d\n", cnt);
			}
			for(int i = 1 ; i <= cnt ; i++)
				st.push(cHeight);

			if (!st.empty()) {
				result++;
			}
			st.push(cHeight);
		} else {
			result++;
			st.push(cHeight);
		}
		//printf("i : %d result : %d\n", i, result);
	}
	cout << result << endl;

	return 0;
}
