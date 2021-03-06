#include <iostream>
#include <vector>
#include <algorithm>

/*
 example)
 10
 8	5	7	12	3	2	11	0	1 	0
 */

using namespace std;

vector<int> arr;

void mSort(int left, int right){
    if (left == right)
        return;
    int mid = (left + right) / 2;
    mSort(left, mid);
    mSort(mid + 1, right);



    int i = left, j = mid + 1;
    int cnt = left;
    vector<int> narr;
    //작은게 앞으로


    while (cnt <= right) {
        if (i > mid) {
            narr.push_back(arr[j]);
            cnt++, j++;
            continue;
        }

        if (j > right) {
            narr.push_back(arr[i]);
            cnt++, i++;
            continue;
        }

        if (arr[i] >= arr[j]) {
            narr.push_back(arr[j]);
            cnt++, j++;
            continue;
        }

        if (arr[i] < arr[j]) {
            narr.push_back(arr[i]);
            cnt++, i++;
            continue;
        }
    }

    for (int k = 0; k < narr.size(); k++) {
        arr[k + left] = narr[k];
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

    mSort(0, num - 1);

    puts("");
    for (int i = 0; i < arr.size(); i++) {
        printf("%d  ", arr[i]);
    }
    puts("");

    return 0;
}
