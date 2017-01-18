

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;

int num, cnt = 0;
int arr[101][101], check[101][101];
P check2[101][101];

int dirCol[4] = {0,0, -1 ,1};
int dirRow[4] = {-1, 1, 0, 0};
vector<int> results;


class Info{
public:
    int row, col, land, cnt;
    Info(int r, int c, int l, int cn){
        row = r, col = c, land = l, cnt = cn;
    }
};

queue<Info> qu2;



void bfs(int row, int col){
    cnt++;
    P p = make_pair(row, col);

    queue<P> qu;
    qu.push(p);
    check[row][col] = cnt;

    while (!qu.empty()) {
        P cp = qu.front();
        qu.pop();

        for (int i = 0; i < 4; i++) {
            int next_row = cp.first + dirRow[i];
            int next_col = cp.second + dirCol[i];

            if (1 <= next_row && next_row <= num && 1 <= next_col && next_col <= num) {
                if (arr[next_row][next_col] == 0){
                    qu2.push(Info(next_row, next_col, cnt, 0));
                    check2[next_row][next_col] = make_pair(cnt, 1);
                }

                if (arr[next_row][next_col] == 1 && check[next_row][next_col] == 0) {
                    check[next_row][next_col] = cnt;
                    qu.push(make_pair(next_row, next_col));
                }
            }
        }
    }
}

int main() {
    scanf("%d", &num);
    vector<pair<int, int>> land;

    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1)
                land.push_back(make_pair(i, j));
        }
    }

    for(P x : land){
        if (check[x.first][x.second] == 0) {
            bfs(x.first, x.second);
        }
    }

    while (!qu2.empty()) {
        Info info = qu2.front();
        qu2.pop();

        for (int i = 0; i < 4; i++) {
            int next_row = info.row + dirRow[i];
            int next_col = info.col + dirCol[i];

            if (1 <= next_row && next_row <= num && 1 <= next_col && next_col <= num) {
                if (arr[next_row][next_col] == 0 && check2[next_row][next_col] == NULL) {
                    check2[next_row][next_col] = make_pair(info.land, info.cnt + 1);
                    qu.push(make_pair(next_row, next_col));
                }
            }
        }
    }

    return 0;
}
