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
    QueueNode* head;
public:
    Queue() {
        this->head = nullptr;
    }

    void enQueue(int val) {
        if (!head) {
            head = new QueueNode(val);
            head->next = head;
            return;
        }

        head->next = new QueueNode(val);
        head->next->next = head;
        head = head->next;
    }

    void deQueue() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        QueueNode* temp = head->next;
        head->next = temp->next;
        delete temp;
    }

    int front() {
        if(head) return head->next->val;
        return -1;
    }
};

int main() {
    Queue Q;
    Q.deQueue();
    Q.enQueue(1);
    Q.enQueue(2);
    Q.enQueue(3);
    Q.enQueue(4);
    cout << Q.front() << endl;
    Q.deQueue();
    cout << Q.front() << endl;
}