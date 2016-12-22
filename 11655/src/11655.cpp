//============================================================================
// Name        : 11655.cpp
// Author      : Kunwoo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

char cstr[101];
string str;

//	97	a
//	122	z
//	65	A
//	90	Z

queue<char> save;

char translate(char a) {
    if (a >= 'a' && a <= 'z') {
        int ai = a + 13;
        if (ai > 'z') {
            return ai - 'z' + 'a' - 1;
        } else {
            return ai;
        }
    }

    if (a >= 'A' && a <= 'Z') {
        int ai = a + 13;
        if (ai > 90) {
            return ai - 'Z' + 'A' - 1;
        } else {
            return ai;
        }
    }
    return a;
}

int main() {
    scanf("%100[0-9a-zA-Z ]", cstr);
    str = cstr;

    for (int i = 0; i < str.length(); i++) {
        char c = str.at(i);
        c = translate(c);
        save.push(c);
    }

    while(!save.empty()){
        cout << save.front();
        save.pop();
    }
    cout << endl;
    return 0;
}


/*
 * java Code
 * import java.util.Scanner;

public class Test {
    static char translate(char a) {
        if (a >= 'a' && a <= 'z') {
            char ai = (char) (a + 13);
            if (ai > 'z') {
                return (char) (ai - 'z' + 'a' - 1);
            } else {
                return ai;
            }
        }

        if (a >= 'A' && a <= 'Z') {
            char ai = (char) (a + 13);
            if (ai > 'Z') {
                return (char) (ai - 'Z' + 'A' - 1);
            } else {
                return ai;
            }
        }
        return a;
    }

    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        StringBuilder sb = new StringBuilder();

        for(int i = 0 ; i < str.length(); i++){
            sb.append(translate(str.charAt(i)));
        }
        System.out.println(sb.toString());
    }
}
 *
 */
