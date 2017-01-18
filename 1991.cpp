#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;

int num;
map<char, int> arr;
map<int, char> tree;

void preorder(int node){
    if(tree.count(node) == 0){
        return;
    }
    printf("%c", tree[node]);
    preorder(node * 2);
    preorder(node * 2 + 1);
}

void inorder(int node){
    if(tree.count(node) == 0){
        return;
    }
    inorder(node * 2);
    printf("%c", tree[node]);
    inorder(node * 2 + 1);
}

void postorder(int node){
    if(tree.count(node) == 0){
        return;
    }
    postorder(node*2);
    postorder(node*2 + 1);
    printf("%c", tree[node]);
}

int main() {
    cin >> num;
    arr['A'] = 1;
    tree[1] = 'A';
    for (int i = 1; i <= num; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        
        int aAddress = arr[a];
            
        if (b != '.') {
            arr[b] = aAddress * 2;
            tree[aAddress * 2] = b;
        }
        
        if (c != '.') {
            arr[c] = aAddress * 2 + 1;
            tree[aAddress * 2 + 1] = c;
        }
    }
    
    preorder(1);
    puts("");
    inorder(1);
    puts("");
    postorder(1);
    puts("");
    
    
    return 0;
}
