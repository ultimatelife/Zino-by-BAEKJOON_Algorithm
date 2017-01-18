#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main() {
    map<string, int> arr;
    arr["black"] = 0;
    arr["brown"] = 1;
    arr["red"] = 2;
    arr["orange"] = 3;
    arr["yellow"] = 4;
    arr["green"] = 5;
    arr["blue"] = 6;
    arr["violet"] = 7;
    arr["grey"] = 8;
    arr["white"] = 9;

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    long long x1, x2, x3;
    x1 = arr[s1];
    x2 = arr[s2];
    x3 = pow(10, arr[s3]);
    cout << (x1*10 + x2) * x3 << endl;

    return 0;
}
