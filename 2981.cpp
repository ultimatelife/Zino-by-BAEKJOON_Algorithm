#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<cmath>

using namespace std;

int uclid(int x, int y){
    int rest = x % y;
    if (rest == 0) {
        return y;
    } else{
        return uclid(y, rest);
    }
}

int main()
{
    int num;
    cin >> num;
    
    vector<int> arr;
    for (int i  = 0; i < num; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end(), less<int>());
    
    int x = arr[0];
    for (int i = 1; i < arr.size(); i++)
        x = uclid(arr[i], x);
    
    
    vector<int> results;
    for (int i = 1; i * x <= arr[num - 1]; i++) {
        int divideNum = i * x;
        int rest = arr[0] % (i * x);
        bool check = true;
        
        for (int j = 1 ; j < num ; j++) {
            if(rest != arr[j] % divideNum){
                check = false;
                break;
            }
        }
        
        if (check)
            results.push_back(divideNum);
    }
    
    for(auto a : results)
        printf("%d ", a);
    puts("");
    
    return 0;
}
