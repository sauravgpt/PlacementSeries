// Minimum number of bracket reversals needed to make an expression balanced
// https://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced/

/*
Input:  exp = "}{"
Output: 2
We need to change '}' to '{' and '{' to
'}' so that the expression becomes balanced, 
the balanced expression is '{}'

Input:  exp = "{{{"
Output: Can't be made balanced using reversals

Input:  exp = "{{{{"
Output: 2 

Input:  exp = "{{{{}}"
Output: 1 

Input:  exp = "}{{}}{{{"
Output: 3
*/

#include<bits/stdc++.h>
using namespace std;

int countReversals(const string &expr) {
    // Step 1: Remove all balanced part;
    // Step 2: Count all unbalanced opened and closed

    int closed = 0;
    int opened = 0;
    for(char c:expr) {
        if(c == '{') opened++;
        else {
            if(opened == 0) closed++;
            else opened--;
        }
    }

    // return ceil(opened/2) + ceil(closed/2)
    return (opened%2 ? opened/2+1 : opened/2) + (closed%2 ? closed/2+1: closed/2);
}

int main() {
    string expr = "{{{{}}";

    cout << countReversals(expr);
}