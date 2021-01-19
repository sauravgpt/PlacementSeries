#include<bits/stdc++.h>
using namespace std;

class Queue {
    class QueueNode {
    public:
        int val;
        QueueNode* next;
        QueueNode(int val = 0) {
            this->val = val;
            this->next = nullptr;
        }
    };

    QueueNode* frnt, * rer;
public:
    Queue() {
        frnt = rer = nullptr;
    }

    void enQueue(int val) {
        if (rer == nullptr) {
            frnt = rer = new QueueNode(val);
            return;
        }

        rer->next = new QueueNode(val);
        rer = rer->next;
    }

    void deQueue() {
        if (frnt == nullptr) return;
        QueueNode* temp = frnt;
        frnt = frnt->next;
        delete temp;
    }

    int front() {
        return frnt->val;
    }

    int rear() {
        return rer->val;
    }
};

int main() {
    Queue Q;
    Q.enQueue(1);
    Q.enQueue(2);
    Q.enQueue(3);
    Q.enQueue(4);
    cout << Q.front() << endl;
    cout << Q.rear() << endl;
    Q.deQueue();
    cout << Q.rear() << endl;
}