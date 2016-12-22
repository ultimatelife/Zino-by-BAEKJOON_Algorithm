#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<string, string> arr;
map<string, int> arrCnt;

string findParent(string str) {
    string temp = str;
    while (arr[str] != str) {
        str = arr[str];
    }
    arr[temp] = str;
    return str;
}

void merge(string s1, string s2) {
    string ps1 = findParent(s1);
    string ps2 = findParent(s2);

    if(ps1 != ps2){
        arr[ps2] = ps1;
        arrCnt[ps1] += arrCnt[ps2];
//        printf("ps1 : %s ps2 : %s cnt : %d\n", ps1.c_str(), ps2.c_str(), arrCnt[ps1]);
    }else{
//        printf("ps1 : %s ps2 : %s cnt : %d\n", ps1.c_str(), ps2.c_str(), arrCnt[ps1]);
    }
    cout << arrCnt[ps1] << endl;

}

int main() {
    int t;
    cin >> t;

    while (t--) {
        arr.clear();
        int num;
        cin >> num;
        while (num--) {
            string s1, s2;
            cin >> s1 >> s2;

            if (arr.count(s1) == 0) {
                arr[s1] = s1;
                arrCnt[s1] = 1;
            }
            if (arr.count(s2) == 0) {
                arr[s2] = s2;
                arrCnt[s2] = 1;
            }
            merge(s1, s2);
        }
    }

    return 0;
}
