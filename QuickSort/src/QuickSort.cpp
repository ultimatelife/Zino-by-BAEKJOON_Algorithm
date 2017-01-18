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

void quickSort(int left, int right){
    int i = left, j = right, mid = (left + right) / 2;

    while (i < j) {
        while (arr[mid] > arr[i]){
            i++;
        }
        while (arr[mid] < arr[j]){
            j--;
        };

        if (i <= j) {
            swap(arr[i++], arr[j--]);
        }
    }

    printf("when left : %d  right : %d  mid : %d\n", left, right, arr[mid]);
    for (int i = left; i <= right; i++) {
        printf("%d  ", arr[i]);
    }
    puts("");
    puts("");

    if (j > left) {
        quickSort(left, j);
    }

    if (i < right) {
        quickSort(i, right);
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

    quickSort(0, num -1);

    puts("");
    for (int i = 0; i < arr.size(); i++) {
        printf("%d  ", arr[i]);
    }
    puts("");

    return 0;
}
