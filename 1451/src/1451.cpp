#include <iostream>
using namespace std;

int rowLength, colLength, maxim;
int allSum = 0;
int arr[101][101] = { { 0, }, };
int check[101][101] = { { 0, }, };

void recur(int sum, int cnt, int mul) {
    if (cnt > 3) {
        if (sum == allSum) {
            if (maxim < mul) {
                maxim = mul;
            }
            return;
        } else {
            return;
        }
    }

    int row = 0, col = 0;
    for (int i = 1; i <= rowLength && (row == 0 && col == 0); i++) {
        for (int j = 1; j <= colLength && (row == 0 && col == 0); j++) {
            if (check[i][j] == 0) {
                row = i, col = j;
                break;
            }
        }
    }
    //printf("cnt : %d sum : %d row : %d col : %d\n", cnt, sum, row, col);

    for (int i = row; i <= rowLength; i++) {
        for (int j = col; j <= colLength; j++) {
            for (int ii = row; ii <= i; ii++) {
                for (int jj = col; jj <= j; jj++) {
                    check[ii][jj] = 1;
                }
            }


            int cSum = 0;
            for (int ii = row; ii <= i; ii++) {
                for (int jj = col; jj <= j; jj++) {
                    cSum += arr[ii][jj];
                }
            }
            recur(sum + cSum, cnt + 1, mul * cSum);

            for (int ii = row; ii <= i; ii++) {
                for (int jj = col; jj <= j; jj++) {
                    check[ii][jj] = 0;
                }
            }
        }
    }
}

int main() {
    cin >> rowLength >> colLength;
    for (int i = 1; i <= rowLength; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= colLength; j++) {
            arr[i][j] = s.at(j - 1) - '0';
            allSum += arr[i][j];
        }
    }
    recur(0, 1, 1);
    cout << maxim << endl;
    return 0;
}
