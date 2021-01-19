#include<bits/stdc++.h>
using namespace std;

class Queue {
    class QueueNode {
    public:
        int val;
        QueueNode* next, * prev;
        QueueNode(int val = 0) {
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
    };

    QueueNode* front, * rear;
public:
    Queue() {
        front = rear = nullptr;
    }

    // insertFront() : Adds an item at the front of Deque.
    // insertRear() : Adds an item at the rear of Deque.
    // deleteFront() : Deletes an item from front of Deque.
    // deleteRear() : Deletes an item from rear of Deque.
    // getFront() : Gets the front item from queue.
    // getRear() : Gets the last item from queue.
    // isEmpty() : Checks whether Deque is empty or not.
    // size() : Gets number of elements in Deque.
    // erase() : Deletes all the elements from Deque.

    void insertFront(int val) {
        if (!rear) {
            front = rear = new QueueNode(val);
        }

        QueueNode* nwNode = new QueueNode(val);
        nwNode->next = front;
        front->prev = nwNode;
        front = nwNode;
    }

    void insertRear(int val) {
        if (!rear) {
            front = rear = new QueueNode(val);
        }

        QueueNode* nwNode = new QueueNode(val);
        nwNode->prev = rear;
        rear->next = nwNode;
        rear = nwNode;
    }

    void deleteFront() {
        if (!front) return;
        if (front == rear) {
            delete front;
            front = rear = nullptr;
            return;
        }

        QueueNode* temp = front;
        front = front->next;
        temp->next = nullptr;
        front->prev = nullptr;
        delete temp;
    }

    void deleteRear() {
        if (!rear) return;
        if (front == rear) {
            delete front;
            front = rear = nullptr;
            return;
        }

        QueueNode* temp = front;
        rear = rear->prev;
        rear->next = nullptr;
        temp->prev = nullptr;
        delete temp;
    }

    int frontEle() {
        if (!front) return -1;
        return front->val;
    }

    int rearEle() {
        if (!rear) return -1;
        return rear->val;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue Q;
    Q.insertFront(1);
    Q.insertFront(2);
    Q.insertRear(3);
    Q.insertRear(4);

    cout << Q.frontEle() << endl;
    cout << Q.rearEle() << endl;
    Q.deleteFront();
    cout << Q.frontEle() << endl;
}