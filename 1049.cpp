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

int needLine, numBrands;
int minPackage = 987654321, minEach = 987654321;

int main()
{
    cin >> needLine >> numBrands;
    for (int i = 0; i < numBrands; i++) {
        int tempPackage, tempEach;
        cin >> tempPackage >> tempEach;
        
        minPackage = min(minPackage, tempPackage);
        minEach = min(minEach, tempEach);
    }
    
    int result = 0;
    if (minPackage >= minEach*6) {
        result = minEach * needLine;
    } else {
        
        //나머지 줄의 개수들을 package로 구매할지 각개로 구매할지
        if((needLine % 6) * minEach > minPackage){
            result = (needLine / 6) * minPackage + minPackage;
        }else{
            result = (needLine / 6) * minPackage + (needLine % 6) * minEach;
        }
    }
    printf("%d\n", result);
    return 0;
}
