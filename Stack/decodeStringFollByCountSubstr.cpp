// https://www.geeksforgeeks.org/decode-string-recursively-encoded-count-followed-substring/

// An encoded string (s) is given, the task is to decode it. The pattern in which the strings are encoded is as follows.

// <count>[sub_str] ==> The substring 'sub_str' 
//                       appears count times.
// Examples:

// Input : str[] = "1[b]"
// Output : b

// Input : str[] = "2[ab]"
// Output : abab

// Input : str[] = "2[a2[b]]"
// Output : abbabb

// Input : str[] = "3[b2[ca]]"
// Output : bcacabcacabcaca

#include<bits/stdc++.h>
using namespace std;

void solve(string& s) {
    int n = s.length();
    string result = "", temp = "";
    stack<char> charS;
    stack<int> countS;


    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            int count = 0;
            while (i < n && isdigit(s[i])) {
                count = count * 10 + s[i] - '0';
            }
            i--;
            countS.push(count);
        }
        else if (s[i] == ']') {
            temp = "";
            int count = 0;
            if (!countS.empty())
                count = countS.top(); countS.pop();
            while (!charS.empty() && charS.top() != '[') temp = charS.top() + temp, charS.pop();
            if (!charS.empty() && charS.top() == '[') charS.pop();

            while (count--) {
                result += temp;
            }
            for (char c : result) charS.push(c);
            result = "";
        }
        else if (s[i] == '[') {
            if (isdigit(s[i - 1])) charS.push(s[i]);
            else {
                countS.push(1);
                charS.push(s[i]);
            }
        }
        else {
            charS.push(s[i]);
        }
    }

    while (!charS.empty()) result = charS.top() + result, charS.pop();
    cout << result;
}

int main() {
    string s = "3[b2[ca]]";
    solve(s);
}