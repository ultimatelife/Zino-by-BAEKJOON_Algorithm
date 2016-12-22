/*
문제
한 배열 A[1], A[2], …, A[n]에 대해서, 부 배열은 A[i], A[i+1], …, A[j-1], A[j] (단, 1≤i≤j≤n)을 말한다. 이러한 부 배열의 합은 A[i]+…+A[j]를 의미한다. 각 원소가 양의 정수인 두 배열 A[1], …, A[n]과 B[1], …, B[m]이 주어졌을 때, A의 부 배열의 합에 B의 부 배열의 합을 더해서 T가 되는 모든 부 배열 쌍의 개수를 구하는 프로그램을 작성하시오.

예를 들어 A={1, 3, 1, 2}, B={1, 3, 2}, T=5인 경우, 부 배열 쌍의 개수는 다음의 7가지 경우가 있다.

T(=5) = A[1] + B[1] + B[2]
  = A[1] + A[2] + B[1]
  = A[2] + B[3]
  = A[2] + A[3] + B[1]
  = A[3] + B[1] + B[2]
  = A[3] + A[4] + B[3]
  = A[4] + B[2]

입력
첫째 줄에 T(1≤T≤1,000,000,000)가 주어진다. 다음 줄에는 n(1≤n≤1,000)이 주어지고, 그 다음 줄에 n개의 자연수로 A[1], …, A[n]이 주어진다. 다음 줄에는 m(1≤m≤1,000)이 주어지고, 그 다음 줄에 m개의 자연수로 B[1], …, B[m]이 주어진다. 각각의 배열 원소는 1,000,000을 넘지 않는 양의 정수 또는 0이다.

출력
첫째 줄에 답을 출력한다. 가능한 경우가 한 가지도 없을 경우에는 0을 출력한다.

예제 입력  복사
5
4
1 3 1 2
3
1 3 2
예제 출력  복사
7
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long num,anum,bnum;
vector<long> a,b,ar,br;

int main() {
    cin >> num;
    cin >> anum;
    for(int i = 0 ; i < anum ; i++){
        int x;
        cin >> x;
        a.push_back(x);
        ar.push_back(x);
    }
    cin >> bnum;
    for(int i = 0 ; i < bnum ; i++){
        int x;
        cin >> x;
        b.push_back(x);
        br.push_back(x);
    }

    for(int i = 0 ; i < anum ; i++){
        long temp = a[i];
        for(int j = i + 1 ; j < anum ; j++){
            temp = temp + a[j];
            ar.push_back(temp);
        }
    }

    for(int i = 0 ; i < bnum ; i++){
        long temp = b[i];
        for(int j = i + 1 ; j < bnum ; j++){
            temp = temp + b[j];
            br.push_back(temp);
        }
    }
    sort(br.begin(), br.end());

    long result = 0;
    for(long x : ar){
        auto range = equal_range(br.begin(), br.end(), num - x);
        result += range.second - range.first;
    }
    cout << result << endl;



    return 0;
}
