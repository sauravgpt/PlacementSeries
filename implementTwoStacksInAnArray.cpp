#include<bits/stdc++.h>
using namespace std;

class Stack {
    int top1, top2;
    int* arr;
    int size;

    bool isArrayFull() {
        return top1 == top2 - 1;
    }

public:
    Stack(int size = 100001) {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }


    void push1(int val) {
        if (isArrayFull()) {
            cout << "Stack overflow\n";
            return;
        }

        arr[++top1] = val;
    }

    void push2(int val) {
        if (isArrayFull()) {
            cout << "Stack overflow\n";
            return;
        }

        arr[--top2] = val;
    }

    bool empty1() {
        return top1 == -1;
    }

    bool empty2() {
        return top2 == size;
    }

    void pop1() {
        if (empty1()) {
            cout << "Stack 1 underflow\n";
            return;
        }

        top1--;
    }

    void pop2() {
        if (empty2()) {
            cout << "Stack 2 underflow\n";
            return;
        }

        top2++;
    }

    int peep1() {
        if(empty1()) return -1;

        return arr[top1];
    }
  
    int peep2() {
        if(empty2()) return -1;

        return arr[top2];
    }
};

int main() {
    Stack S(10);

    S.push1(1);
    S.push1(1);
    S.push1(1);
    S.push1(1);
    S.push1(1);
    S.push1(1);
    S.push1(1);
    S.push1(1);
    S.push1(1);
    S.push1(1);
    S.push1(1);
    S.push1(1);
    cout << S.peep1() << endl;
    cout << S.peep2() << endl;
}