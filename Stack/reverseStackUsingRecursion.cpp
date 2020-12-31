// Problem: https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

// Note: Without extra space even without using functional stack can be 
// implemented if stack if implemented through linked list, just we need to
// reverse the linked list.
 

#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &S, int val) {
    if(S.empty()) {
        S.push(val);
        return;
    }

    int x = S.top(); S.pop();
    insert(S, val);
    S.push(x);
}

void reverse(stack<int> &S) {
    if(S.empty()) return;
    int x = S.top(); S.pop();
    reverse(S);
    insert(S, x);
}

int main() {    
    stack<int> S;
    for(int i=1; i<=5; i++) S.push(i);
    reverse(S);
    while(!S.empty()) cout << S.top() << " ", S.pop();
}