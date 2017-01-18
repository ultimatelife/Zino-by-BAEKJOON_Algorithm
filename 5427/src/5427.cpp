#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int tc;
int row, col;

int dirRow[4] = {0, 0, 1, -1};
int dirCol[4] = {1, -1, 0, 0};

class Info{
public:
    int row;
    int col;
    char ty;
    int cnt;

    Info (int r, int c, char t, int cn){
        row = r;
        col = c;
        ty = t;
        cnt = cn;
    }
};

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &col, &row);
        char arr[1001][1001];
        queue<Info> qu;

        Info sang(0,0,'c', 0);
        vector<Info> fires;

        for (int i = 1 ; i <= row; i++) {
            string temp;
            cin >> temp;
            for (int j = 1; j <= temp.length(); j++) {
                arr[i][j] = temp[j - 1];

                if (temp[j-1] == '@') {
                    sang = Info(i, j, '@', 0);
                }

                if (temp[j-1] == '*') {
                    fires.push_back(Info(i,j,'*', 0));
                }
            }
        }



//        printf("사람 위치 : %d %d\n", sang.row, sang.col);
        //불
        for (int i = 0; i < fires.size(); i++) {
//            printf("불 위치 : %d %d\n", fires[i].row, fires[i].col);
            qu.push(fires[i]);
        }
        //사람
        qu.push(sang);

        bool isPossible = false;
        int result = 0;
        while (!qu.empty() && isPossible == false) {
//            puts("");
//            for (int i = 1 ; i <= row; i++) {
//                for (int j = 1; j <= col; j++) {
//                    printf("%c ", arr[i][j]);
//                }
//                puts("");
//            }

            Info cInfo = qu.front();
            qu.pop();

            //printf("%c 위치 : %d %d\n", cInfo.ty , cInfo.row, cInfo.col);

            if (cInfo.ty == '@') {
                for (int i = 0; i < 4; i++) {
                    int nextRow = cInfo.row + dirRow[i];
                    int nextCol = cInfo.col + dirCol[i];

                    if (nextRow > row || nextRow <= 0 || nextCol > col || nextCol <= 0) {
                        result = cInfo.cnt + 1;
                        isPossible = true;
                        break;
                    } else{
                        if (arr[nextRow][nextCol] == '.') {
                            arr[nextRow][nextCol] = '@';
                            Info nextInfo(nextRow, nextCol, '@', cInfo.cnt + 1);
                            qu.push(nextInfo);
                        }
                    }
                }
            }

            if (cInfo.ty == '*') {
                for (int i = 0; i < 4; i++) {
                    int nextRow = cInfo.row + dirRow[i];
                    int nextCol = cInfo.col + dirCol[i];

                    if (nextRow > row || nextRow <= 0 || nextCol > col || nextCol <= 0) {

                    } else {
                        if (arr[nextRow][nextCol] == '.' || arr[nextRow][nextCol] == '@') {
                            arr[nextRow][nextCol] = '*';
                            Info nextInfo(nextRow, nextCol, '*', cInfo.cnt + 1);
                            qu.push(nextInfo);
                        }
                    }
                }
            }

        }

        if (isPossible) {
            printf("%d\n", result);
        }else{
            printf("%s\n", "IMPOSSIBLE");
        }

        //puts("");
//        for (int i = 1 ; i <= row; i++) {
//            for (int j = 1; j <= col; j++) {
//                printf("%c ", arr[i][j]);
//            }
//            puts("");
//        }
    }



    return 0;
}
