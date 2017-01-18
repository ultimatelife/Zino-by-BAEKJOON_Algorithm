/*
 n
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<bitset>

using namespace std;

int E, S, M, Y;
int oE, oS, oM;
int lE = 15, lS = 28, lM = 19;

int transfer(int x, int divideNum){
    if (x % divideNum == 0) {
        return divideNum;
    }
    return x % divideNum;
}

int main()
{
    cin >> E >> S >> M;
    Y = E, oE = E, oS = E, oM = E;
    
    while (true) {
        if (oE == E && oS == S && oM == M) {
            printf("%d\n", Y);
            return 0;
        }
        Y += 15;
        
        oS = transfer(Y, 28);
        oM = transfer(Y, 19);
    }
    
    
    return 0;
}
