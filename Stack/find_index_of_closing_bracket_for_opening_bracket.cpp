// Problem: https://www.geeksforgeeks.org/find-index-closing-bracket-given-opening-bracket-expression/

#include<bits/stdc++.h>
using namespace std;

int findIndex(const string& expr, int idx) {
    if (expr[idx] != '[')
        return -1;

    int counter = 0;
    for (int i = idx; i < expr.length(); i++) {
        if (expr[i] == '[') counter++;
        else if (expr[i] == ']') counter--;

        if (counter == 0)
            return i;
    }
    return -1;
}

int main() {
    string expr = "[ABC[23]][89]";
    int index = 0;

    cout << findIndex(expr, index) << endl;
}