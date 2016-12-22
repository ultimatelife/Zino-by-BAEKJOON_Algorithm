//============================================================================
// Name        : 1158.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    deque<int> de;
    for(int i = 0 ; i < n ; i++){
        de.push_back(i + 1);
    }

    string str = "<";
    int cnt = 0;
    while(!de.empty()){
        cnt++;
        int x = de.front();
        de.pop_front();

        if(cnt % m == 0){
            if(str.length() == 1){
                str += to_string(x);
            }else{
                str = str + ", " + to_string(x);
            }
        }else{
            de.push_back(x);
        }
    }
    str += ">";
    cout << str << endl;
    return 0;
}
