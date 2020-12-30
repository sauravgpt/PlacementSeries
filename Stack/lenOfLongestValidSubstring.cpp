// Length of the longest valid substring
// https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/

/*
Input : ((()
Output : 2
Explanation : ()

Input: )()())
Output : 4
Explanation: ()()

Input:  ()(()))))
Output: 6
Explanation:  ()(())
*/

#include<bits/stdc++.h>
using namespace std;

int countValid(const string& expr) {
    // Step 1 : Count all unbalanced opened and closed brackets

    int unbalancedOpened = 0;
    int unbalancedClosed = 0;

    for (char c : expr) {
        if (c == '(') unbalancedOpened++;
        else {
            if (unbalancedOpened == 0) unbalancedClosed++;
            else unbalancedOpened--;
        }
    }

    return expr.length() - (unbalancedClosed + unbalancedOpened);
}

int main() {
    string expr = "()(()))))";
    cout << countValid(expr);
}