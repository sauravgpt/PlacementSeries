#include<bits/stdc++.h>
using namespace std;

class Stack {
public:
    queue<int> Q1;
    queue<int> Q2;

    bool empty() {
        return Q1.empty();
    }

    void push(int val) { //O(n)
        while (!Q1.empty()) {
            Q2.push(Q1.front());
            Q1.pop();
        }

        Q1.push(val);

        while (!Q2.empty()) {
            Q1.push(Q2.front());
            Q2.pop();
        }
    }

    void pop() {
        if (!Q1.empty()) {
            Q1.pop();
            return;
        }
        cout << "Stack underflow\n";
    }

    int top() {
        if (!Q1.empty())
            return Q1.front();


        return -1;
    }
};

int main() {
    Stack S1;

    S1.push(1);
    S1.push(2);
    S1.push(3);
    S1.push(4);
    S1.push(5);
    S1.push(6);
    cout << S1.top() << endl;
    S1.pop();
    cout << S1.top() << endl;
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
}