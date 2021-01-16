// https://www.geeksforgeeks.org/form-minimum-number-from-given-sequence/

// Given a pattern containing only I’s and D’s. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern. Digits from 1-9 and digits can’t repeat.

// Examples: 

//    Input: D        Output: 21
//    Input: I        Output: 12
//    Input: DD       Output: 321
//    Input: II       Output: 123
//    Input: DIDI     Output: 21435
//    Input: IIDDD    Output: 126543
//    Input: DDIDDIID Output: 321654798

#include<bits/stdc++.h>
using namespace std;
unordered_set<int> S;

void solve(string& s, long osf, int index) {
    cout << index << " ";
    if (index >= s.length()) {
        cout << osf << endl;
        return;
    }

    if (s[index] == 'I') {
        int x = osf % 10;
        for (int i = x;i <= 9; i++) {
            if (i > x && !S.count(i)) {
                osf = osf * 10 + i;
                S.insert(i);
                solve(s, osf, index + 1);
                osf /= 10;
                S.erase(i);
            }
        }
    }
    else {
        int x = osf % 10;
        for (int i = x;i > 0; i--) {
            if (i > x && !S.count(i)) {
                osf = osf * 10 + i;
                S.insert(i);
                solve(s, osf, index + 1);
                osf /= 10;
                S.erase(i);
            }
        }
    }
}

int main() {
    string s = "DIDI";
    long num = 0;
    if (s[0] == 'D') num = 2;
    else num = 1;
    solve(s, num, 0);
}