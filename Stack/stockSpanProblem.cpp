#include<bits/stdc++.h>
using namespace std;

vector<int> StockSpan(vector<int> &prices) {
    vector<int> res;

    stack<int> S;

    for(int i=0; i<prices.size(); i++) {
        while(!S.empty() && prices[S.top()] <= prices[i])
            S.pop();

        if(S.empty()) res.push_back(1);
        else res.push_back(i-S.top());

        S.push(i);
    }
    return res;
}

int main() {
    vector<int> V = {100, 80, 60, 70, 60, 75, 85};
    vector<int> res = StockSpan(V);
    for(int i:res) cout << i << " ";
    
}