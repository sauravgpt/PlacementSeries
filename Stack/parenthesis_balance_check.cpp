#include<bits/stdc++.h>
using namespace std;

bool check(string expression) {
    stack<char> S;

    for(char e:expression) {
        if(e == '{' || e == '[' || e == '(')
            S.push(e);
        else {
            if(S.empty()) return false;
            if(e == '}' && S.top() != '{') return false;
            if(e == ']' && S.top() != '[') return false;
            if(e == ')' && S.top() != '(') return false;
            S.pop();
        }
    }

    return true;
}

int main() {
    string exprr =  "[()]{}{[()()]()}";

    if(check(exprr)) cout << "Balanced\n";
    else cout << "Unbalanced\n";
}