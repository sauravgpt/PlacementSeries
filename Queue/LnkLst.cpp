#include<bits/stdc++.h>
using namespace std;

class LinkNode {
public:
    int x;
    LinkNode* next;
    LinkNode(int x = 0) {
        this->x = x;
        next = NULL;
    }
};

class LinkList {
    LinkNode* head;
public:
    LinkList() {
        head = NULL;
    }

    void insertAtBeg(int value) {
        LinkNode* node = new LinkNode(value);

        if (head == NULL)
        {
            head = node;
            return;
        }

        node->next = head;
        head = node;
    }

    void insert(int value) {
        LinkNode* node = new LinkNode(value);

        if (head == NULL)
        {
            head = node;
            return;
        }
        LinkNode* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = node;
    }

    void printList() {

        LinkNode* curr = head;
        while (curr != NULL) {
            cout << curr->x << " ";
            curr = curr->next;
        }
    }

    void deleteNode() {
        if(head == NULL) return;

        LinkNode *curr = head;
        LinkNode *prev = head;

        while(curr->next) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        delete curr;
    }
};

int main() {
    LinkList L;
    L.insert(10);
    L.insert(13);
    L.insert(10);
    L.insert(45);
    L.insert(50);
    L.insert(70);
    L.insert(10);
    L.printList();
    cout << endl;
    L.deleteNode();
    L.printList();
    cout << endl;
    L.insertAtBeg(56);
    L.printList();
    cout << endl;

// 10 13 10 45 50 70 10
// 10 13 10 45 50 70

// 10 13 10 45 50 70 10 
// 10 13 10 45 50 70
// 56 10 13 10 45 50 70
}
