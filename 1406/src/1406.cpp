#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>

using namespace std;

int main() {
    string s;
    int t;
    cin >> s;
    cin >> t;

    deque<char> de1, de2;

    for (int i = 0 ; i < s.length(); i++) {
        de1.push_back(s.at(i));
    }
    while (t--) {
        char c;
        cin >> c;

        if(c == 'L'){
            if(!de1.empty()){
                char temp = de1.back();
                de1.pop_back();
                de2.push_back(temp);
            }
        }else if (c == 'D'){
            if(!de2.empty()){
                char temp = de2.back();
                de2.pop_back();
                de1.push_back(temp);
            }
        }else if(c == 'B'){
            if(!de1.empty()){
                de1.pop_back();
            }
        }else if(c == 'P'){
            cin >> c;
            de1.push_back(c);
        }
    }

    while(!de1.empty()){
        cout << de1.front();
        de1.pop_front();
    }

    while (!de2.empty()) {
        cout << de2.back();
        de2.pop_back();
    }
    puts("");

    return 0;
}
