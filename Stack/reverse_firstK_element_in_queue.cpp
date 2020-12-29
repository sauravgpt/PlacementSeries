#include<bits/stdc++.h>
using namespace std;

void solve(queue<int>& Q, int k) {
    int n = Q.size();
    stack<int> S;
    while (!Q.empty()) {
        S.push(Q.front());
        Q.pop();
    }

    while (!S.empty()) {
        Q.push(S.top());
        S.pop();
    }

    for (int i = 0; i < n - k; i++) {
        S.push(Q.front());
        Q.pop();
    }

    while (!S.empty()) {
        Q.push(S.top());
        S.pop();
    }
}

int main() {
    queue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);
    Q.push(6);
    Q.push(7);
    Q.push(8);
    Q.push(9);
    Q.push(10);

    int k = 4;

    // 1 2 3 4 5
    // 2 1 3 4 5

    solve(Q, k);

    while (!Q.empty()) {
        cout << Q.front() << " ";
        Q.pop();
    }
}