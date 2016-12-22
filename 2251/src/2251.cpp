#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct Nums{
    int a;
    int b;
    int c;
};

int check[201][201] ={{0,},};
vector<int> save;
int a,b,c;
int am =1000000, bm=1000, cm = 1;
int limit[3], arr[3] = {0,}, nextArr[3] = {0,};

int main() {
    cin >> limit[0] >> limit[1] >> limit[2];
    queue<Nums> qu;
    qu.push(Nums{0,0,limit[2]});
    check[0][limit[2]] = true;
    save.push_back(limit[2]);


    while(!qu.empty()){
        Nums temp = qu.front();
        arr[0] = temp.a;
        arr[1] = temp.b;
        arr[2] = temp.c;
        qu.pop();
//        printf("a : %d b : %d c : %d\n", temp.a, temp.b, temp.c);

        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(i == j)
                    continue;
                nextArr[2] = arr[2];
                nextArr[1] = arr[1];
                nextArr[0] = arr[0];


                if(arr[i] == 0)
                    continue;
                if(arr[j] == limit[j])
                    continue;
                int enableJ = limit[j] - arr[j];

                if(enableJ > arr[i]){
                    nextArr[j] = arr[i] + arr[j];
                    nextArr[i] = 0;
                }else{
                    nextArr[j] = limit[j];
                    nextArr[i] = arr[i] - enableJ;
                }

                Nums tempNums;
                tempNums.a = nextArr[0];
                tempNums.b = nextArr[1];
                tempNums.c = nextArr[2];

                if(check[nextArr[0]][nextArr[2]] == false){
//                    printf("a : %d b : %d c : %d\n", tempNums.a, tempNums.b, tempNums.c);
                    check[nextArr[0]][nextArr[2]] = true;
                    qu.push(tempNums);
                    if(tempNums.a == 0)
                        save.push_back(tempNums.c);
                }
            }
        }
    }

    int check2[201] = {0,};
    sort(save.begin(), save.end());
    for(int i = 0 ; i < save.size() ; i++){
        if(check2[save[i]] == 0) {
            cout << save[i] << " ";
            check2[save[i]] = 1;
        }
    }
    puts("");

    return 0;
}
