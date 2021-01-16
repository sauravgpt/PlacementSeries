#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &S, int val) {
    if(S.empty() || S.top() <= val) {
        S.push(val);
        return;
    }

    int temp = S.top(); S.pop();
    insert(S, val);
    S.push(temp);
}

void sort(stack<int> &S) {
    if(S.empty()) 
        return;

    int temp = S.top(); S.pop();
    sort(S);
    insert(S, temp);
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