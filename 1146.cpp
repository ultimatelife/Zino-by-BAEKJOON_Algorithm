#include <iostream>

using namespace std;

#define UP 0
#define DOWN 1
#define MOD 1000000


int cache[2][110][110];

int func(int UpDown, int upCounts, int downCounts) {
    if (UpDown == UP && upCounts ==0) {
        return 0;
    }
    
    else if (UpDown == UP && upCounts == 1 && downCounts == 0) {
        return 1;
    }

    if (UpDown == DOWN && downCounts == 0) {
        return 0;
    }
    else if (UpDown == DOWN && upCounts == 0 && downCounts == 1) {
        return 1;
    }

    int &ret = cache[UpDown][upCounts][downCounts];

    if (ret != -1)
        return ret;


    int sum = 0;

    if (UpDown == UP) {

        for (int i = 1; i <= upCounts; i++) {
            sum += func(DOWN, upCounts - i, downCounts + i - 1) % MOD;
            sum %= MOD;
        }

    }
    else {

        for (int i = 1; i <= downCounts; i++) {
            sum += func(UP, upCounts + i - 1, downCounts - i) % MOD;
            sum %= MOD;
        }
        
    }

    ret = sum;

    return ret;
}


int main() {


    for (int i = 0; i < 110; i++) {
        for (int j = 0; j < 110; j++) {
            cache[UP][i][j] = -1;
            cache[DOWN][i][j] = -1;
        }
    }

    int num;

    cin >> num;

    if (num == 1) {
        cout << "1" << endl;
        return 0;
    }

    int sum = 0;


    for (int i = 0; i < num; i++) {

        sum += func(UP, i, num - i - 1);
        sum %= MOD;
        sum += func(DOWN, i, num - i - 1);
        sum %= MOD;
    }

    cout << sum % MOD << endl;

/*
    for (int i = 0; i <= num; i++) {
        for (int j = 0; j <= num; j++) {


            cout << cache[0][i][j] << " " ;


        }
        cout << endl;
    }
*/

    return 0;
}