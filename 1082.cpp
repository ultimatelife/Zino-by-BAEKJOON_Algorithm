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

int N, money;


int compareNums(int arr1[10], int arr2[10], int N, int money, int num){
//    printf("when money : %d num : %d ", money, num);
    
    int cntArr1 = 0, cntArr2 = 0;
    for (int i = N; i >= 0; i--) {
        cntArr1 += arr1[i];
        cntArr2 += arr2[i];
    }
    
    if (cntArr1 == arr1[0] && cntArr2 == arr2[0]) {
        if (cntArr1 > cntArr2) {
            return 1;
        }else if(cntArr1 < cntArr2){
            return -1;
        }else{
            return 0;
        }
    }
    
    if(cntArr1 > cntArr2){
        if (cntArr1 == arr1[0] && cntArr2 != arr2[0] ) {
            return -1;
        }
        return 1;
    }
    
    if(cntArr1 < cntArr2){
        if (cntArr2 == arr2[0] && cntArr1 != arr1[0]) {
            return 1;
        }
        return -1;
    }

    for (int i = N; i >= 1; i--) {
        if (arr1[i] > arr2[i]){
//            cout << "wow" << endl;
            return 1;
        }
        
        else if( arr1[i] < arr2[i] ){
//            cout << "vov" << endl;
            return -1;
        }
        
    }
    return 0;
}

int main()
{
    int t = 3;
    while (t--) {
        int minNum = 10, minCost = 51;
        int nums[10] = {0,}, dp2[51][10] = {{0,},};
    
        
        cin >> N;
        for (int i = 0; i < N; i++){
            cin >> nums[i];
            if (nums[i] <= minCost) {
                if (nums[i] == minCost) {
                    if (i > minNum) {
                        minNum = i;
                    }
                } else{
                    minNum = i;
                    minCost = nums[i];
                }
            }
        }
        cin >> money;
        
        
        for (int i = minCost; i <= money; i++) {
            int tempArr[10] = {0,};
            for (int j = 0; j < N; j++) {
                if (i - nums[j] >= 0) {
                    for (int k = 0 ; k < N; k++) {
                        tempArr[k] = dp2[i - nums[j]][k];
                    }
//                    copy(&dp2[i - nums[j]][0], &dp2[i - nums[j]][9] + 1, &tempArr[0]);
                    tempArr[j]++;
                    
                    
//                    printf("temp : ");
//                    for (int k = 0 ; k < N ; k++) {
//                        printf("%d ", tempArr[k]);
//                    }
//                    puts("");
                    
                    int com = compareNums(dp2[i], tempArr, N, i, j);
//                    printf("com : %d\n", com);
                    if (com == -1){
                        for (int k = 0 ; k < N; k++) {
                            dp2[i][k] = tempArr[k];
                        }
//                        copy(&tempArr[0], &tempArr[9] + 1, &dp2[i][0]);
                    }
                    
                }
            }
            
//            printf("dp[%d] : ", i);
//            for (int k = 0 ; k < N ; k++) {
//                printf("%d ", dp2[i][k]);
//            }
//            puts("");
            
//            printf("result : ");
//            for (int k = 9; k >= 0; k--) {
//                int x = dp2[i][k];
//                for (int j = 0 ; j < x ; j++) {
//                    printf("%d", k);
//                }
//            }
//            puts("");
        }
        
//        printf("result : ");
        for (int i = 9; i >= 0; i--) {
            int x = dp2[money][i];
            for (int j = 0 ; j < x ; j++) {
                printf("%d", i);
            }
        }
        puts("");
        
        
    }

    
    return 0;
}
