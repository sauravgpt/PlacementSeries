#include<bits/stdc++.h>
using namespace std;

class Stack {
    int top;
    int* arr;
    int size;

public:
    Stack(int size = 100001) {
        this->arr = new int[size];
        this->size = size;
    }

    void pop();
    void push(int val);
    int peep();
    bool empty() { return (this->top == -1); }
    bool isFull() { return (top == size); }
};

void Stack::push(int val) {
    if (isFull()) {
        cout << "Stack Overflow\n";
        return;
    }

    arr[++top] = val;
}

void Stack::pop() {
    if (empty()) {
        cout << "Stack underflow\n";
        return;
    }
    top--;
}

int Stack::peep() {
    if (empty()) {
        cout << "Stack empty\n";
        return -1;
    }

    return arr[top];
}

int main() {
    Stack S1(5);

    S1.push(1);
    S1.push(2);
    S1.push(3);
    S1.push(4);
    S1.push(5);
    S1.push(6);
    cout << S1.peep() << endl;
    S1.pop();
    cout << S1.peep() << endl;
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
    S1.pop();
}