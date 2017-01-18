
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Info{
public:
    long long sameCnt;
    long long height;
    
    Info(long long h, long long s){
        height = h;
        sameCnt = s;
    }
};

int main() {
    long long num;
    vector<long long> arr;
    cin >> num;
    for (long long i = 0 ; i < num; i++) {
        long long x;
        cin >> x;
        arr.push_back(x);
    }
    
    stack<Info> st;
    long long result = 0;
    long long cnt = 0;
    
    for(long long x : arr){
        cnt++;
        Info cInfo(x, 0);
        if(st.empty()){
            st.push(cInfo);
            continue;
        }
        
        if (st.top().height <= cInfo.height) {
            while (!st.empty() && st.top().height <= cInfo.height) {
                //prlong longf("when %d top.height = %d     cIfno.height = %d\n", cnt, st.top().height, cInfo.height);
                if(st.top().height == cInfo.height){
                    cInfo.sameCnt = st.top().sameCnt + 1;
                    result += (cInfo.sameCnt);
//                    prlong longf("pop1\n");
                } else{
//                    prlong longf("pop2\n");
                    result += (st.top().sameCnt + 1);
                }
                st.pop();
            }
            
            if(!st.empty())
                result++;
        }else{
            result++;
        }
        st.push(cInfo);
        
        //prlong longf("when %d : height : %d result = %d top.sameCnt = %d\n", cnt, cInfo.height, result, st.top().sameCnt);
    }
    cout << result << endl;
    
    return 0;
}
