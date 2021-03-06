#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

string n;
long long d, length;

long long getNumber(int index){
    int indexNum = n[index] - '0';

    if (index == length - 1) {
        if(indexNum >= d){
            return 1;
        } else{
            return 0;
        }
    }

    long long sum = 0;
    int calLength = length - (index + 1);

    if (index == 0 && d == 0) {
        sum += (indexNum  * pow(10, calLength - 1) * calLength);

        long long dsum = 0;
        for (int i = 0 ; i < calLength; i++) {
            dsum += (pow(10, i));
        }
        sum -= dsum;
        sum += getNumber(index + 1);
    } else {
        sum += (indexNum * pow(10, calLength - 1) * calLength);

        if (d < indexNum) {
            sum += pow(10, length - index - 1);
        } else if (d == indexNum){
            int rest = stoi(n.substr(index + 1, length - index)) + 1;
            sum += rest;
        }
        sum += getNumber(index + 1);
    }
    return sum;
}


int main() {
    cin >> n >> d;
    length = n.length();
    long long result = getNumber(0);
    cout << result << endl;
    return 0;
}
