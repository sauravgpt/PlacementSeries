#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val = 0) {
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

// [  prev | val | next ] -> Node

// 1

class Stack {
    Node* head;
    Node* insert(Node* head, int val) {
        if (!head) {
            return new Node(val);
        }

        Node* newNode = new Node(val);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;

        return head;
    }

public:
    Stack() {
        head = nullptr;
    }

    void push(int val) {
        this->head = insert(this->head, val);
    }
};

