//============================================================================
// Name        : 2331.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int a,p;
int check[10000000];

int translate(int num){
    int result = 0;
    while(num > 0){
        result += pow(num % 10, p);
        num /= 10;
    }
    return result;
}

int length(int num, int cnt){
    if(check[num]){
        return check[num] - 1;
    }
    check[num] = cnt;
    return length(translate(num), cnt + 1);
}

int main() {
    cin >> a >> p;
    cout << length(a, 1) << endl;
    return 0;
}
