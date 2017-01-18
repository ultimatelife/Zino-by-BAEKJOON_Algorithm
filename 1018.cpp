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

int n,m, result = 251;
int arr1[51][51], arr2[51][51], chess[51][51];

int getMin(int startRow, int startCol){
    int temp1 = 0, temp2 = 0;
    for (int i = startRow; i - startRow < 8; i++) {
        for (int j = startCol; j - startCol < 8; j++) {
            if(arr1[i - startRow][j - startCol] != chess[i][j])
                temp1++;
            
            if(arr2[i - startRow][j - startCol] != chess[i][j])
                temp2++;
        }
    }
    return min(temp1, temp2);
}

int main()
{
    cin >> n >> m;
    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            if (str[j] == 'W')
                chess[i][j] = 1;
            
            
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    arr1[i][j] = 1;
                }else{
                    arr2[i][j] = 1;
                }
            }else{
                if (j % 2 == 0) {
                    arr2[i][j] = 1;
                } else {
                    arr1[i][j] = 1;
                }
            }
        }
    }
    
    for (int i = 0; i <= n - 8; i++)
        for (int j = 0; j <= m - 8; j++)
            result = min(result, getMin(i, j));
    
    printf("%d\n", result);
    
    
    return 0;
}
