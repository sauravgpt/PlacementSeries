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

class EffMinStack {
    stack<int> S;
    int minVal;

public:
    void push(int val) {
        if (S.empty()) {
            S.push(val);
            minVal = val;
            return;
        }

        if (val < minVal) {
            int num = 2 * val - minVal;
            minVal = val;
            S.push(num);
        }
        else {
            S.push(val);
        }
    }

    void pop() {
        if (S.empty()) return;

        if (S.top() < minVal) {
            minVal = minVal * 2 - S.top();
        }

        S.pop();
    }

    int getTop() {
        if (S.empty()) return -1;

        if (S.top() < minVal)
            return minVal;

        return S.top();
    }

    int getMin() {
        if (S.empty()) return -1;
        return minVal;
    }
};

int main() {
    EffMinStack S;
    S.push(22);
    S.push(23);
    cout << S.getMin() << endl;
    cout << S.getTop() << endl;
    S.push(15);
    S.push(46);
    cout << S.getMin() << endl;
    cout << S.getTop() << endl;
    S.push(21);
    cout << S.getTop() << endl;
}