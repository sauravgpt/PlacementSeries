#include<bits/stdc++.h>
using namespace std;

// S = [5 4 3 2 1]

int reverse(int num) {
    int res = 0;

    stack<int> S;
    while(num > 0) {
        S.push(num%10);
        num /= 10;
    }

    int counter = 1;
    while(!S.empty()) {
        int x = S.top(); S.pop();
        res += counter*x;
        counter *= 10;
    }

    return res;
}

int main() {
    int num = 12345;

    cout << reverse(num) << endl;
}