#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val = 0) {
        this->val = val;
        next = nullptr;
    }
};

class LinkedList {
    ListNode* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtLast(int val) {
        ListNode* node = new ListNode(val);
        if (head == nullptr) {
            head = node;
            return;
        }

        ListNode* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = node;
    }

    void deleteAtLast() {
        if (head == nullptr) return;

        ListNode* curr = head;
        ListNode* prev = head;
        while (curr->next) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = nullptr;
        delete curr;
    }

    void printList() {
        ListNode *curr = head;
        while(curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
    }
};

int main() {
    LinkedList L;
    L.insertAtLast(10);
    L.insertAtLast(20);
    L.insertAtLast(30);
    L.insertAtLast(40);
    L.insertAtLast(50);
    L.insertAtLast(60);
    L.printList();
}