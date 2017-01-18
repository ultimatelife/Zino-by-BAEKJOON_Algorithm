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

bool arr[100001];
int old, young;

int main()
{
    cin >> old >> young;
    
    queue<P> qu;
    arr[old] = 1;
    qu.push(make_pair(old, 0));
    
    while (!qu.empty()) {
        P p = qu.front();
        qu.pop();
        
        if (p.first == young) {
            printf("%d\n", p.second);
            return 0;
        }
        
        
        if (!(p.first - 1 < 0) && arr[p.first - 1] == 0) {
            qu.push(make_pair(p.first - 1, p.second + 1));
            arr[p.first - 1] = 1;
        }
        
        if (!(p.first + 1 > 100000) && arr[p.first + 1] == 0) {
            qu.push(make_pair(p.first + 1, p.second + 1));
            arr[p.first + 1] = 1;
        }
        
        if (!(p.first*2 > 100000) && arr[p.first*2] == 0) {
            qu.push(make_pair(p.first*2 , p.second + 1));
            arr[p.first*2] = 1;
        }
    }
    
    return 0;
}
