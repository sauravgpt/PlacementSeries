// Problem: https://www.geeksforgeeks.org/next-greater-element/
/*
Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1.

Examples:

1. For any array, rightmost element always has next greater element as -1.
2. For an array which is sorted in decreasing order, all elements have next greater element as -1.
3. For the input array {4, 5, 2, 25}, the next greater elements for each element are as follows.
*/

#include<bits/stdc++.h>
using namespace std;


vector<int> naiveNGE(vector<int>& arr) { // Naive approach -> O(n^2)
    int n = arr.size();
    if (n == 0)
        return {};

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                ans[i] = arr[j];
                break;
            }
        }
    }

    return ans;
}

vector<int> NGE(vector<int>& arr) {
    int n = arr.size(); if (!n) return {};

    vector<int> ans(n, -1);
    stack<int> S;

    for(int i=n-1; i>=0; i--) {
        while(!S.empty() && arr[S.top()] < arr[i]) S.pop();

        if(!S.empty()) ans[i] = arr[S.top()];
        S.push(i);
    }

    return ans;
}


int main() {
    vector<int> arr = { 4, 5, 2, 25 };
    vector<int> ans1 = NGE(arr);
    for (int i : ans1) cout << i << " ";
}