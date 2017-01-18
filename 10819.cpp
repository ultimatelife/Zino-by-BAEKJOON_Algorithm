#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<cmath>

using namespace std;

int main()
{
    int num = 0;
    cin >> num;
    vector<int> arr;
    for (int i = 0; i < num; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    sort(arr.begin(), arr.end());
    
    int result = 0;
    do{
        int temp = 0;
        for (int i = 0; i < num - 1; i++) {
            temp += abs(arr[i] - arr[i + 1]);
        }
        result = max(result, temp);
    } while (next_permutation(arr.begin(), arr.end()));
    cout << result << endl;
    
    return 0;
}
