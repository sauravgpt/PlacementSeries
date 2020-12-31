// Problem: https://www.geeksforgeeks.org/the-celebrity-problem/

/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.


Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0},
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity.

Example 2:

Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.

Your Task:
You don't need to read input or print anything. Complete the function celebrity() which takes the matrix M and its size N as input parameters and returns the index of the celebrity. If no such celebrity is present, return -1.
*/
#include<bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>>& M, int a, int b) {
    return M[a][b] == 1;
}

int celebrity(vector<vector<int>>& M, int n) {
    if (n <= 1) return -1;
    stack<int> S;
    for (int i = 0; i < n; i++) S.push(i);

    int A = S.top(); S.pop();
    int B = S.top(); S.pop();

    while (S.size() > 1) {
        if (knows(M, A, B)) {
            A = S.top(); S.pop();
        }
        else {
            B = S.top(); S.pop();
        }
    }

    if (S.empty()) {
        bool a = knows(M, A, B);
        bool b = knows(M, B, A);

        if (a && b) return -1;
        if (!a && b) return A;
        if (a && !b) return B;
    }

    int C = S.top(); S.pop();
    if (knows(M, C, A)) C = A;
    if (knows(M, C, B)) C = B;
    
    for (int i = 0; i < n; i++) {
        if (i != C && (knows(M, C, i) || !knows(M, i, C))) return -1;
    }

    return C;
}

int main() {
    vector<vector<int>> M = { {0, 0, 1, 0},
                               {0, 0, 1, 0},
                               {0, 0, 0, 0},
                               {0, 0, 1, 0} };

    int celeb = celebrity(M, M.size());

    cout << celeb << endl;
}