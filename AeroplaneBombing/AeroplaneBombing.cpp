#include<vector>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int ans;

void dfs(vector<vector<int>> &grid, int level, int posi, int coin, int remain, vector<vector<pair<int,int>>>&memo){
    if(level < 0  || posi<0 || posi >= 5)  return;

    if(memo[level][posi].second!=INT_MAX && memo[level][posi].second<remain || memo[level][posi].first < coin){
        memo[level][posi].first = coin;
        memo[level][posi].second = remain;

        if(grid[level][posi] == 1) coin++;
        else if(grid[level][posi] == 2){
            if(remain == -1) remain = 5;
            else if(remain <= 0) return;
        }
        if(remain != INT_MAX && remain > 0) remain--;

        ans = max(ans, coin);
        dfs(grid, level-1, posi-1, coin,  remain, memo);
        dfs(grid, level-1, posi, coin,  remain, memo);
        dfs(grid, level-1, posi+1, coin,  remain, memo);
    }
}

int main(void){
    int t;cin>>t;
    for(int tt=1;tt<=t;tt++){
        ans = INT_MIN;
        int n;
        cin >> n;
        vector<vector<int>> grid(n+1, vector<int>(5,0));
        vector<vector<pair<int, int>>> memo(n+1, vector<pair<int,int>>(5,{-1, INT_MAX}));
        for(int i=0;i<n;i++)for(int j=0;j<5;j++) cin>>grid[i][j];

        dfs(grid, n, 2, 0, -1, memo);
        cout << "#"<< tt  << " " << ans << endl;
    }
}
