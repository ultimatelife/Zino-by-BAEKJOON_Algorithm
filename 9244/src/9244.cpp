#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

const int INF = -1000001;
int lineNum, ballX, ballY = 1000001;

class Info{
public:
    float x1, x2, y1, y2, a, b, endX, endY;
    int sX, sY;
    
    Info(float x_1, float y_1, float x_2, float y_2){
        if (x_1 > x_2) {
            x1 = x_1, y1 = y_1, x2 = x_2, y2 = y_2;
        } else {
            x1 = x_2, y1 = y_2, x2 = x_1, y2 = y_1;
        }
        
        if (y_2 < y_1) {
            endX = x_2;
            endY = y_2;
        }else{
            endX = x_1;
            endY = y_1;
        }
        
        a = (y_2 - y_1) / (x_2 - x_1);
        b = y_1 - a * x_1;
    }
    
    void setSx(int x){
        sX = x;
        sY = (a * x) + b;
    }
    
    bool operator < (Info i) const{
        return sY < i.sY;
    }
};

vector<Info> lines;
map<int, priority_queue<Info>> arr;

int main() {
    scanf("%d", &lineNum);
    while (lineNum--) {
        int a,b,c,d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        lines.push_back(Info(a,b,c,d));
    }
    scanf("%d", &ballX);
    
    for(auto a : lines){
        for (int i = a.x2; i <= a.x1; i++) {
            a.setSx(i);
            arr[i].push(a);
//            printf("at x : %d \t (%f %f %f %f) (%d %d)\n", i, a.x1, a.y1, a.x2, a.y2, a.sX, a.sY);
        }
    }
    ballY = -INF;
    
    while (arr.count(ballX) != 0 && !arr[ballX].empty()) {
        priority_queue<Info> qu = arr[ballX];
//        printf("ballX : %d  ballY : %d\n", ballX, ballY);
        
        bool isOk = true;
        int next_ballX = ballX, next_ballY = ballY;
        while (!qu.empty() && isOk) {
            if (qu.top().sY < ballY) {
                next_ballX = qu.top().endX;
                next_ballY = qu.top().endY;
                qu.pop();
                break;
            }
            qu.pop();
        }
        
        if (next_ballX == ballX && next_ballY == ballY) {
            break;
        }else{
            ballX = next_ballX;
            ballY = next_ballY;
        }
        
    }
    
    int result = ballX;
    printf("%d\n", result);
    return 0;
}