// Problem: https://www.geeksforgeeks.org/find-next-smaller-next-greater-array/

/*
Given array of integer, find the next smaller of next greater element of every element in array.

Note : Elements for which no greater element exists or no smaller of greater element exist, print -1.

Examples:

Input : arr[] = {5, 1, 9, 2, 5, 1, 7}
Output:          2  2 -1  1 -1 -1 -1
Explanation :
Next Greater ->      Right Smaller
   5 ->  9             9 ->  2
   1 ->  9             9 ->  2
   9 -> -1            -1 -> -1
   2 ->  5             5 ->  1
   5 ->  7             7 -> -1
   1 ->  7             7 -> -1
   7 -> -1            -1 -> -1

Input  : arr[] = {4, 8, 2, 1, 9, 5, 6, 3}
Output :          2  5  5  5 -1  3 -1 -1
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> NSofNG(vector<int>& arr) {
    int n = arr.size(); if (!n) return {};

    stack<int> S;
    int NG[n];

    for (int i = n - 1; i >= 0; i--) {
        while (!S.empty() && arr[S.top()] <= arr[i]) S.pop();

        if (S.empty()) NG[i] = -1;
        else NG[i] = S.top();
        S.push(i);
    }

    while (!S.empty()) S.pop();
    vector<int> NS(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!S.empty() && arr[S.top()] >= arr[i]) S.pop();

        if (S.empty()) NS[i] = -1;
        else NS[i] = S.top();
        S.push(i);
    }

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (NG[i] != -1 && NS[NG[i]] != -1) {
            ans.push_back(arr[NS[NG[i]]]);
        } else {
            ans.push_back(-1);
        }
    }

    return ans;
}

int main() {
    vector<int> arr = { 5, 1, 9, 2, 5, 1, 7 };
    vector<int> ans = NSofNG(arr);
    for (int i : ans) cout << i << " ";
    cout << endl;
}