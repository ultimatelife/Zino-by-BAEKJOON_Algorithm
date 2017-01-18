#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

int num;
vector<int> arr1(1000,0), arr2(1000,0);
queue<int> qu;

int numCheck(int x){
    if (x == 0)
        return 0;
    if (x > 0)
        return 1;
    return -1;
}

int getStackValue(queue<int> qu, int cMin){
    if (qu.size() != 1) {
//        printf("cMin : %d\n", cMin);
    }
    
    if (qu.size() == 1){
        int x = cMin;
//        printf("cMin(end) : %d\n", cMin);
        qu.pop();
        return x;
    }
    
    
    int result = cMin;
    int nextMin = 81;
    queue<int> nextQu;
    
    while (!qu.empty()) {
        int x = qu.front() - cMin;
        qu.pop();
        if (x == 0) {
            if (!nextQu.empty()) {
                queue<int> nextQu2;
                while (!nextQu.empty()) {
//                    printf("%d ", nextQu.front());
                    nextQu2.push(nextQu.front());
                    nextQu.pop();
                }
//                puts("");
//                puts("");
                result += getStackValue(nextQu2, nextMin);
                nextMin = 81;
            }
        } else{
            nextQu.push(x);
            nextMin = min(nextMin, x);
        }
        
        if (qu.empty()) {
            if (!nextQu.empty()) {
//                printf("마지막\n");
                result += getStackValue(nextQu, nextMin);
            }
        }
    }
    
    return result;
}

int main()
{
    cin >> num;
    for (int i = 0 ; i < num; i++)
        cin >> arr1[i];
    
    for (int i = 0 ; i < num; i++)
        cin >> arr2[i];
    
    for (int i = 0 ; i < num; i++){
//        int x;
//        cin >> x;
//        qu.push(x);
        qu.push(arr2[i] - arr1[i]);
    }
    
    int result = 0;
    while (!qu.empty()) {
        int x = qu.front();
        int xState = numCheck(x);
        qu.pop();
        
        if (xState == 1) {
            queue<int> nextQu;
            int cMin = x;
            nextQu.push(x);
            
            while (!qu.empty() && numCheck(qu.front()) == xState) {
                nextQu.push(qu.front());
                cMin = min(cMin, qu.front());
                qu.pop();
            }
            result += getStackValue(nextQu, cMin);
            continue;
        }
        
        if (xState == -1) {
            queue<int> nextQu;
            int cMin = -x;
            nextQu.push(-x);
            
            while (!qu.empty() && numCheck(qu.front()) == xState) {
                nextQu.push((-qu.front()));
                cMin = min(cMin, (-qu.front()));
                qu.pop();
            }
            result += getStackValue(nextQu, cMin);
            continue;
        }
    }
    printf("%d\n", result);
    
    return 0;
}
