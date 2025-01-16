#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;
struct point{int x,y;};

int totalCost(vector<point> &customer,  int n, int curr, int mask, vector<vector<int>>&memo, point home){
    if(mask == ((1<<n)-1)) return abs(customer[curr].x - home.x)+abs(customer[curr].y-home.y);
    if (memo[curr][mask] != -1) return memo[curr][mask];

    int ans=INT_MAX;
    for(int i=0; i<n; i++){
        if((mask & (1<<i)) == 0){
            ans = min(ans, abs(customer[curr].x - customer[i].x) + abs(customer[curr].y - customer[i].y)
                      + totalCost(customer, n, i, (mask | (1<<i)), memo, home));
        }
    }
    return memo[curr][mask] = ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    for(int t=1; t<=10; t++){
        int n;cin>>n;
        vector<point> customer(n+1);
        point home;
        vector<vector<int>> memo(n+1, vector<int>((1<<(n+1)),-1));

        cin >> customer[0].x >> customer[0].y >> home.x >> home.y;
        for(int i=1;i<=n;i++) cin >> customer[i].x >> customer[i].y;

        cout << "# " << t << " " << totalCost(customer, n+1, 0, 1, memo,home) << endl;
    }
    return 0;
}
