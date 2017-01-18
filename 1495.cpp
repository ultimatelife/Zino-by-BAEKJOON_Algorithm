
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n,s,m;
int v[101] = {0,};

int findResult(set<int> arr, int cnt){
    if(arr.empty()){
//        printf("1) cnt : %d\n", cnt);
        return -1;
    }
    
    
    if(cnt > n){
//        printf("2) cnt : %d\n", cnt);
        return *max_element(arr.begin(), arr.end());
    }
    
    set<int> nexrArr;
    for(int i : arr){
        int plus = i + v[cnt];
        int minus = i - v[cnt];
        if(plus <= m)
            nexrArr.insert(plus);
        
        if(minus >= 0)
            nexrArr.insert(minus);
    }
    return findResult(nexrArr, cnt + 1);
}

int main() {
    cin >> n >> s >> m;
    for(int i = 1 ; i<= n ; i++)
        cin >> v[i];
    
    set<int> first;
    first.insert(s);
    cout << findResult(first, 1) << endl;
    
    return 0;
}