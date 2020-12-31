// Problem: https://www.geeksforgeeks.org/find-maximum-difference-between-nearest-left-and-right-smaller-elements/

/*
Given an array of integers, the task is to find the maximum absolute difference between the nearest left and the right smaller element of every element in the array.

Note: If there is no smaller element on right side or left side of any element then we take zero as the smaller element. For example for the leftmost element, the nearest smaller element on the left side is considered as 0. Similarly, for rightmost elements, the smaller element on the right side is considered as 0.

Examples:

Input : arr[] = {2, 1, 8}
Output : 1
Left smaller  LS[] {0, 0, 1}
Right smaller RS[] {1, 0, 0}
Maximum Diff of abs(LS[i] - RS[i]) = 1

Input  : arr[] = {2, 4, 8, 7, 7, 9, 3}
Output : 4
Left smaller   LS[] = {0, 2, 4, 4, 4, 7, 2}
Right smaller  RS[] = {0, 3, 7, 3, 3, 3, 0}
Maximum Diff of abs(LS[i] - RS[i]) = 7 - 3 = 4

Input : arr[] = {5, 1, 9, 2, 5, 1, 7}
Output : 1
*/

#include<bits/stdc++.h>
using namespace std;

int findDiff(vector<int>& arr) {
    int n = arr.size(); if (!n) return {};

    int L[n], R[n];
    stack<int> S;

    for (int i = 0; i < n; i++) {
        while (!S.empty() && arr[S.top()] >= arr[i]) S.pop();

        if (S.empty()) L[i] = 0;
        else L[i] = arr[S.top()];
        S.push(i);
    }

    while (!S.empty()) S.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!S.empty() && arr[S.top()] >= arr[i]) S.pop();

        if (S.empty()) R[i] = 0;
        else R[i] = arr[S.top()];
        S.push(i);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, abs(L[i] - R[i]));
    }

    return ans;
}

int main() {
    vector<int> arr = { 2, 4, 8, 7, 7, 9, 3 };
    cout << findDiff(arr) << endl;
}