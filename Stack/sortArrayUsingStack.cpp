#include<bits/stdc++.h>
using namespace std;

void sort(vector<int>& arr) {
    int beg = 0;
    int n = arr.size();

    stack<int> S;

    while(beg < n) {
        int x = arr[beg++];
        while(!S.empty() && S.top() < x) arr[--beg] = S.top(), S.pop();
        S.push(x);        
    }
    beg = 0;
    while(!S.empty()) {
        arr[beg++] = S.top();
        S.pop();
    }
}

int main() {
    vector<int> arr = { 2,1,3,5,4 };
    sort(arr);
    for(int i:arr) cout << i << " ";
}