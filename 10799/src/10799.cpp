#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Info{
public:
    int cnt;
    int index;
    
    Info (int c, int i){
        cnt = c;
        index = i;
    }
};

int main() {
    string s;
    cin >> s;
    stack<Info> st;
    
    
    int result = 0;
    for(int i = 0 ; i < s.length() ; i++){
        string c = s.substr(i, 1);
        if(st.empty()){
            st.push(Info(0, i));
            continue;
        }
        
        if(c == "("){
            st.push(Info(0, i));
        }else{
            // when = ')'
            Info *top = &st.top();
            
            if(top->index == i - 1){
                st.pop();
                if(!st.empty()){
                    Info *cTop = &st.top();
                    cTop->cnt++;
                }
            } else {
                st.pop();
                result += (top->cnt + 1);
                //printf("i : %d  result : %d\n",i, result);
                if(!st.empty())
                    st.top().cnt += top->cnt;
            }
        }
    }
    
    cout << result << endl;

    return 0;
}
