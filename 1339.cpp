#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<cmath>

using namespace std;
typedef pair<string, int> P;
typedef map<char, vector<int>>::iterator IT;

int num, numAl;
vector<string> arr;
int mymap[27][8];
int check[27], check2[27];
int results[27];

int getBestNum(int c1, int c2){
    for (int i = 7 ; i >= 0; i--) {
        if (mymap[c1][i] > mymap[c2][i])
            return 1;
        if (mymap[c1][i] < mymap[c2][i])
            return -1;
    }
    return 0;
}


int main()
{
    cin >> num;
    while (num--) {
        string str;
        cin >> str;
        
        arr.push_back(str);
        for (int i = 0 ; i < str.length() ; i++) {
            if (check[ str[i] - 'A'] == 0) {
                check[ str[i] - 'A'] = 1;
                numAl++;
            }
            mymap[ str[i] - 'A' ][ str.length() - i - 1 ]++;
        }
    }

    for (int i = 9 ; ; i--) {
        char mChar = 0, mCnt = -1;
        
        for (int j = 0 ; j < 26 ; j++) {
            int tempC = j;
            int tempCnt = 0;
            
            if (check2[j] == 1)
                continue;
            
            if (mCnt == -1) {
                mChar = tempC;
                mCnt = tempCnt;
                continue;
            }
            
            if (getBestNum(mChar, tempC) == -1) {
                mChar = tempC;
                mCnt = tempCnt;
            }
        }
        
        if (mCnt != -1){
            results[mChar] = i;
            check2[mChar] = 1;
//            printf("mChar : %c  value : %d\n", mChar + 'A', i);
        }
        
        if (i == 0)
            break;
        
        
    }
    
    
    int sum = 0;
    for(auto a : arr){
        for (int i = 0; i < a.length(); i++) {
            a[i] = results[a[i] - 'A'] + '0';
        }
//        cout << a << endl;
        sum += stoi(a);
    }
    printf("%d\n", sum);
    
    return 0;
}
