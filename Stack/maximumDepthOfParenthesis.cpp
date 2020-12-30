#include<bits/stdc++.h>
using namespace std;

int findParenthesisDepth(const string& expr) {

    int count = 0;
    int maxDepth = 0;
    for (char c : expr) {
        if (c == '(') count++;
        else if (c == ')') count--;
        maxDepth = maxDepth < count ? count : maxDepth;
    }

    return maxDepth;
}

int main() {
    string expr = "( a(b) (c) (d(e(f)g)h) I (j(k)l)m)";
    cout << findParenthesisDepth(expr);
}