#include <iostream>
#include <algorithm>
using namespace std;

int w,m,k;
int result = 0;

void recur(int w, int m){
    int temp = 0;
    temp = min(w/2, m);
    if(result < temp){
        result = temp;
    }
}

int main() {
    cin >> w >> m >> k;

    for(int i = 0 ; i <= k ; i++){
        if(w - i >= 2 && m - (k - i) >= 1)
            recur(w - i, m - (k - i));
    }
    cout << result << endl;
    return 0;
}
