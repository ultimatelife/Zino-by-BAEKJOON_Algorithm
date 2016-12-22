#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int t, from, to;
    cin >> t;

    int notPrimary[10000] = {0,};
    for(int i = 2 ; i < 10000 ; i++){
        for(int j = i + i ; j < 10000 ; j = j + i){
            notPrimary[j] = 1;
        }
    }

    while(t--){
        cin >> from >> to;
        int check[10000];
        fill(&check[0], &check[10000] + 1, -1);

        queue<string> qu;
        qu.push(to_string(from));
        check[from] = 0;

        while (!qu.empty()) {
            string x = qu.front();
            qu.pop();
            if(atoi(x.c_str()) == to){
                break;
            }


            for(int i = 0 ; i < 4 ; i++){
                for(int j = 0 ; j <= 9 ; j++){
                    string temp = x;
                    temp[i] = j + '0';
                    int changedNum = atoi(temp.c_str());

                    if(notPrimary[changedNum] == 0 && changedNum >= 1000 && check[changedNum] == -1){
                        check[changedNum] = check[atoi(x.c_str())] + 1;
                        qu.push(temp);
                    }

                }
            }
        }
        if(check[to] == -1){
            cout << 0 << endl;
        }else{
            cout << check[to] << endl;
        }

    }

    return 0;
}
