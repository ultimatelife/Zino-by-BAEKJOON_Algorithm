#include <iostream>
#include <vector>
#include <algorithm>

/*
 example)
10
8	5	7	12	3	2	11	6	1 	2
 */

using namespace std;
vector<int> arr;

void selectionSort(){
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    int num = 0;
    cin >> num;
    for (int i = 0 ; i < num; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    selectionSort();

    puts("");
    for (int i = 0; i < arr.size(); i++) {
        printf("%d  ", arr[i]);
    }
    puts("");

    return 0;
}
