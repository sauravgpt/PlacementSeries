#include<bits/stdc++.h>
using namespace std;

class Stack {
    int k;
    int* top;
    int* arr;
    int size;
public:
    Stack(int k, int size = 100) {
        top = new int[k];
        arr = new int[size];
        this->k = k;
        this->size = size;

        //arr = [ 0 1 2 | 3 4 5 | 6 7 8 9 ]
//                            ^
        int index = 0;
        for (int i = -1; i < (k - 1) * size / k; i += size / k) {
            top[index] = i;
            index++;
        }
    }

    bool empty(int stackNumber) {
        stackNumber++;
        if (stackNumber == k) return top[stackNumber - 1] != size - 1;

        return top[stackNumber - 1] != (stackNumber * k) - 1;
    }

    void push(int stackNumber, int val) {
        if (stackNumber > k) {
            cout << "Invalid Stack Number\n";
            return;
        }

        stackNumber--;

        if (!empty(stackNumber)) {
            cout << "Stack " << stackNumber + 1 << " Overflows\n";
            return;
        }

        arr[++top[stackNumber]] = val;
    }

    void pop(int stackNumber) {
        stackNumber--;
        if (empty(stackNumber)) {
            cout << "Stack " << stackNumber + 1 << " Underflows\n";
            return;
        }

        top[stackNumber]--;
    }

    int peep(int stackNumber) {
        stackNumber--;
        if (top[stackNumber] == ((k - 1) * size / k) - 1) {
            return -1;
        }

        return arr[top[stackNumber]];
    }
};

int main() {
    Stack S(3, 10);
    S.push(1, 10);
    S.pop(2);
    S.push(3, 50);
    cout << S.peep(1) << endl;
    S.push(3, 40);
    cout << S.peep(3) << endl;
}