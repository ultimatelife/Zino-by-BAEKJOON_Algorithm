#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long t, from , to;
    scanf("%lld", &t);

    while (t--) {
        scanf("%lld %lld", &from, &to);
        to = to - from;

        long long n, rest;
        n = sqrt(to);
        rest = to - pow(n, 2);
        long long cnt = 0;
        while (rest > 0) {
            cnt++;
            rest -= n;
        }

        long long result = cnt + n * 2 - 1;
        printf("%lld\n", result);
    }

    return 0;
}
