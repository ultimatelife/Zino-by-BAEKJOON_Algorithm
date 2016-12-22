
#include <iostream>
#include <vector>
using namespace std;

int num;
vector<int> arr;

void recur(string str, int start, int cnt){
    if(cnt >= 6){
        cout << str << endl;
        return;
    }

    for(int i = start ; i < num ; i++){
        if(cnt > 0)
            recur(str + " " + to_string(arr[i]), i + 1, cnt + 1);
        else
            recur(to_string(arr[i]), i + 1, cnt + 1);
    }
}

int main() {
    while(true){
        cin >> num;
        arr.clear();
        if(num == 0)
            break;

        for(int i = 1 ; i <= num ; i++){
            int x;
            cin >> x;
            arr.push_back(x);
        }
        recur("", 0, 0);
        puts("");
    }
    return 0;
}
