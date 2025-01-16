// Using Top-Down DP (Memoization) – O(n*n*2^n) Time and O(n*2^n) Space

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int totalCost(vector<vector<int>> &cost, int n, int curr, int mask, vector<vector<int>> &memo){
    if(mask == (1<<n)-1) return cost[curr][0];
    if(memo[curr][mask] != -1) return memo[curr][mask];

    int minCost = INT_MAX;
    for(int i=0; i<n; i++){
        if((mask & (1<<i)) == 0){
            minCost = min(minCost, cost[curr][i] + totalCost(cost, n, i, mask | (1<<i), memo));
        }
    }
    return memo[curr][mask] = minCost;
}

int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<vector<int>> cost(n, vector<int>(n));
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>> cost[i][j];
        vector<vector<int>> memo(n, vector<int> (1<<n, -1));
        cout << totalCost(cost, n,0, 1, memo) << endl;
    }

    return 0;
}

