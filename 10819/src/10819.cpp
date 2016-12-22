//============================================================================
// Name        : 10819.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> arr;

int num, maxim = 0;

int main() {
    cin >> num;
    for (int i = 1; i <= num; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    int result = 0;
    do{
        int sum = 0;
        for(int i = 0 ; i < num - 1 ; i++){
            sum = abs(arr[i]  - arr[i+1]) + sum;
        }
        if(result < sum)
            result = sum;
    }while(next_permutation(arr.begin(), arr.end()));
    cout << result << endl;

    return 0;
}

//int main() {
//	cin >> num;
//	arr.assign(9, 1);
//	for (int i = 0; i < num; i++) {
//		cin >> arr[i];
//	}
//	sort(arr.begin(), &arr[num]);
//	for (int i = 0; i < num; i++) {
//		cout << arr[i] << " ";
//	}
//	puts("");
//
//	int left = 0, right = arr.size() - 1;
//	while (left <= right) {
//		if (left == right) {
//			int leftVal = arr[left];
//			int ll = abs(save.front() - leftVal);
//			int rl = abs(save.back() - leftVal);
//			if (ll > rl) {
//				save.push_front(leftVal);
//			} else {
//				save.push_back(leftVal);
//			}
//			break;
//		}
//		int leftVal = arr[left];
//		int rightVal = arr[right];
//
//		if (save.empty()) {
//			save.push_back(leftVal);
//			save.push_back(rightVal);
//			left++, right--;
//			continue;
//		}
//
//		//When leftVal pushed
//		int ll = abs(save.front() - leftVal);
//		int rl = abs(save.back() - leftVal);
//		if (ll > rl) {
//			save.push_front(leftVal);
//		} else {
//			save.push_back(leftVal);
//		}
//
//		//When rightVal pushed
//		ll = abs(save.front() - rightVal);
//		rl = abs(save.back() - rightVal);
//		if (ll > rl) {
//			save.push_front(rightVal);
//		} else {
//			save.push_back(rightVal);
//		}
//		left++, right--;
//	}
//
//	int sum = 0;
//	for(int i = 0 ; i < save.size() - 1 ; i++){
//		cout << save.at(i) << " ";
//		sum += (abs(save.at(i) - save.at(i + 1)));
//	}
//	puts("");
//	cout << sum << endl;
//
//	return 0;
//}
