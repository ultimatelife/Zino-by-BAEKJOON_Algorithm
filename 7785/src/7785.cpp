#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool strCompare(string s1, string s2){
	return s1 < s2;
}

int main() {
    int n;
    cin >> n;
    set<string, string> s;
    while (n--) {
        string name, what;
        cin >> name >> what;
        if (what == "enter") {
            s.insert(name);
        } else {
            s.erase(s.find(name));
        }
    }



    vector<string> arr;

    arr.push_back("easdv");
    arr.push_back("aasdf");
    arr.push_back("dsdf");
    arr.push_back("dasdf");

    sort(arr.begin(), arr.end());
    for(auto s : arr)
    	cout << s << endl;


    return 0;
}
