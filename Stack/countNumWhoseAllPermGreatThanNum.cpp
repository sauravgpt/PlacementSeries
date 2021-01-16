// https://www.geeksforgeeks.org/count-natural-numbers-whose-permutation-greater-number/

// There are some natural number whose all permutation is greater than or equal to that number eg. 123, whose all the permutation (123, 231, 321) are greater than or equal to 123.

// Given a natural number n, the task is to count all such number from 1 to n.

// Examples:

// Input : n = 15.
// Output : 14
// 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 
// 13, 14, 15 are the numbers whose all 
// permutation is greater than the number
// itself. So, output 14.

// Input : n = 100.
// Output : 54

#include<bits/stdc++.h>
using namespace std;

void solve(int n) {
    int result = 0;

    for (int i = 1; i <= 9; i++) {
        stack<int> S;
        if (i <= n) {
            cout << i << " ";
            S.push(i);
            result++;
        }

        while (!S.empty()) {
            int tp = S.top(); S.pop();
            for (int j = tp % 10; j <= 9; j++) {
                int x = tp*10 + j;
                if(x <= n) {
                    cout << x << " ";
                    S.push(x);
                    result++;
                } else {
                    break;
                }
            }
        }
    }

    cout << endl << result;
}

int main() {
    int n; cin >> n;
    solve(n);
}