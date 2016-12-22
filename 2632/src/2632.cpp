#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int num, aNum, bNum, sum = 0;
    cin >> num;
    cin >> aNum >> bNum;
    vector<int> a(aNum), b(bNum), ar, br;

    for(int i = 0 ; i < aNum ; i++){
        int x;
        cin >> x;
        a[i] = x;
        ar.push_back(x);
        sum += x;
    }
    ar.push_back(0);
    ar.push_back(sum);

    sum = 0;
    for(int i = 0 ; i < bNum ; i++){
        int x;
        cin >> x;
        b[i] = x;
        br.push_back(x);
        sum += x;
    }
    br.push_back(0);
    br.push_back(sum);

    for(int i = 0 ; i < aNum ; i++){
        int temp = a[i];
        for(int j = 1 ; j < aNum - 1 ; j++){
            int index = i + j <= aNum - 1 ? i + j : i + j - aNum;
            temp += a[index];
            ar.push_back(temp);
        }
    }
    for(int i = 0 ; i < bNum ; i++){
        int temp = b[i];
        for(int j = 1 ; j < bNum - 1 ; j++){
            int index = i + j <= bNum - 1 ? i + j : i + j - bNum;
            temp += b[index];
            br.push_back(temp);
        }
    }
    sort(ar.begin(), ar.end());

//    puts("show ar");
//    for(int x : ar){
//        cout << x << endl;
//    }
//    puts("end ar");
//    puts("");

    sort(br.begin(), br.end());

    int result = 0;
    for(int x : ar){
        auto range = equal_range(br.begin(), br.end(), num - x);
        result += range.second - range.first;
    }
    cout << result << endl;



    return 0;
}
