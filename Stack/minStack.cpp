#include<bits/stdc++.h>
using namespace std;

class Stack {
    stack<int> S;
    stack<int> minS;

public:
    void push(int val) {
        if (S.empty()) {
            S.push(val);
            minS.push(val);
            return;
        }

        S.push(val);
        minS.push(min(minS.top(), val));
    }

    void pop() {
        if (!S.empty()) {
            S.pop();
            minS.pop();
        }
    }

    int top() {
        if (!S.empty()) return S.top();

        return -1;
    }

    int minVal() {
        if (!minS.empty()) return minS.top();

        return -1;
    }

};

int main() {
    Stack S;
    S.push(22);
    S.push(23);
    S.push(15);
    S.push(46);
    S.push(21);

    cout << S.minVal() << endl;
    cout << S.top() << endl;
}