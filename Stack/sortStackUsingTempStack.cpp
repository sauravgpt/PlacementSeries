#include<bits/stdc++.h>
using namespace std;

void sort(stack<int> &S) {
    stack<int> tempS;

    while(!S.empty()) {
        int x = S.top(); S.pop();
        while(!tempS.empty() && tempS.top() > x)
            S.push(tempS.top()), tempS.pop();

        tempS.push(x);
    }

    S = tempS;
}

int main() {
    stack<int> S;
    
    S.push(2);
    S.push(3);
    S.push(1);
    S.push(4);
    S.push(5);

    sort(S);
    while(!S.empty()) cout << S.top() << " ", S.pop();
}