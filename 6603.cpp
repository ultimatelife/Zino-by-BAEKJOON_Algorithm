#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<cmath>

using namespace std;

int limit;

void printNums(vector<int> arr, vector<int> next_arr, int startIndex){
    if (next_arr.size() >= 6) {
        for(auto a : next_arr)
            printf("%d ", a);
        puts("");
        next_arr.pop_back();
        return;
    }
    
    for (int i = startIndex; i < arr.size(); i++) {
        next_arr.push_back(arr[i]);
        printNums(arr, next_arr, i + 1);
        next_arr.pop_back();
    }
}

int main()
{
    while (true) {
        cin >> limit;
        if (limit == 0)
            break;
        
        vector<int> arr(limit, 0);
        vector<int> next_arr;
        
        for (int i = 0; i < limit; i++)
            cin >> arr[i];
        
        sort(arr.begin(), arr.end(), less<int>());
        printNums(arr, next_arr, 0);
        puts("");
    }
    
    return 0;
}
