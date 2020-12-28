#include<bits/stdc++.h>
using namespace std;

class Queue {
public:
    stack<int> S1;
    stack<int> S2;

    bool empty() {
        return S1.empty() && S2.empty();
    }

    void push(int val) {
        S1.push(val);
    }

    void pop() {
        if (this->empty()) return;

        if (S2.empty()) {
            while (!S1.empty()) {
                S2.push(S1.top());
                S1.pop();
            }
        }

        S2.pop();
    }

    int front() {
        if (empty()) return -1;

        if (S2.empty()) {
            while (!S1.empty()) {
                S2.push(S1.top());
                S1.pop();
            }
        }

        return S2.top();
    }
};

int main() {
    Queue Q;

    Q.push(1);
    Q.push(2);
    Q.push(3);
    cout << Q.front() << endl;
    Q.pop();
    Q.push(4);
    Q.pop();
    cout << Q.front() << endl;
}