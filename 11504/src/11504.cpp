//============================================================================
// Name        : 11504.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int size;
int arr1[1001];
int arr2[1001];
int fromLeftDp[1001];
int fromRightDp[1001];

void findDp(int arr[], int dp[]) {
    for (int i = 2; i <= size; i++) {
        int max = 1, temp;
        for (int j = 1; j < i; i++) {
            if (arr[i - 1] < arr[i]) {
                temp = dp[i - j] + 1;

                if (temp > max) {
                    max = temp;
                }
            }
        }
        dp[i] = max;
    }
}

int main() {
    cin >> size;
    for (int i = 1; i <= size; i++) {
        int temp;
        cin >> temp;
        arr1[i] = temp;
        arr2[i] = temp;
    }
    reverse(begin(arr2) + 1, end(arr2));

    for (int i = 1; i <= size; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    fromLeftDp[0] = 0, fromLeftDp[1] = 1;
    fromRightDp[0] = 0,fromRightDp[1] = 1;

    findDp(arr1, fromLeftDp);
    findDp(arr2, fromRightDp);

    for (int i = 1; i <= size; i++) {
        fromLeftDp[i] = fromLeftDp[i] + fromRightDp[i];
    }

    cout << *max_element(begin(fromLeftDp), end(fromLeftDp)) << endl;

    return 0;
}
