#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int burst(vector<int>&balloons,int N, vector<vector<int>>&dp, int left, int right){
    if(left>right) return 0;
    if(dp[left][right] != -1) return dp[left][right];

    int maxScore = -1, temp;
    for(int i=left; i<=right; i++) {
        if(left == 1 && right == N){
            //Assume that balloons[i] will be bursted in last
            maxScore = max(maxScore, balloons[i] + burst(balloons,N, dp, left, i-1) + burst(balloons,N, dp, i+1, right));
        }
        else {
            maxScore = max(maxScore, balloons[left-1]*balloons[right+1] + burst(balloons,N, dp, left, i-1)+burst(balloons,N, dp, i+1, right));
        }
    }
    return dp[left][right] = maxScore;
}

int main(void){
    int n; cin>>n;
    vector<int> balloons(n+2);
    vector<vector<int>> dp(n+2,vector<int>(n+2, -1));
    for(int i=1;i<=n;i++) cin>> balloons[i];
    balloons[0] = 1;
    balloons[n+1] = 1;

    cout << burst(balloons,n, dp, 1, n);
}
