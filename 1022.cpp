#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<cmath>

using namespace std;
typedef pair<int, int> P;
typedef long long ll;

int r1,r2,c1,c2;
ll numLength;
ll arr[51][51];

int convertNumber(int row, int col){
    if (row == 0 && col == 0)
        return 1;
    
    int n = max(abs(row), abs(col));
    int length = n*2 + 1;
    
    int sNum = 1 + 4*n*(n+1);
    if (row == n && col == n){
        if (numLength < to_string(sNum).length())
            numLength = to_string(sNum).length();
        return sNum;
    }
    
    
    int temp;
    if (row == n)
        temp = n - col;
    else if (col == -n)
        temp = n - row + (length - 1);
    else if (row == -n)
        temp = n + col + (length - 1)*2;
    else
        temp = n + row + (length - 1)*3;;
    
    if (numLength < to_string(sNum - temp).length())
        numLength = to_string(sNum - temp).length();
    
    return sNum - temp;
}

int main()
{
    cin >> r1 >> c1 >> r2 >> c2;
    
    for (int i = r1; i <= r2; i++){
        for (int j = c1; j <= c2; j++){
            arr[i - r1][j - c1] = convertNumber(i, j);
        }
    }
    
    for (int i = r1; i <= r2; i++){
        for (int j = c1; j <= c2; j++){
            printf("%*d ", numLength, arr[i - r1][j - c1]);
        }
        puts("");
    }
    

    return 0;
}
