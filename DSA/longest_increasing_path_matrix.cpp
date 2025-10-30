#include <bits/stdc++.h>
using namespace std;
class Solution {
    int dfs(int i,int j,vector<vector<int>>&m,vector<vector<int>>&dp){
        if(dp[i][j]) return dp[i][j];
        int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        int best=1;
        for(auto&d:dirs){
            int x=i+d[0],y=j+d[1];
            if(x>=0&&y>=0&&x<m.size()&&y<m[0].size()&&m[x][y]>m[i][j])
                best=max(best,1+dfs(x,y,m,dp));
        }
        return dp[i][j]=best;
    }
public:
    int longestIncreasingPath(vector<vector<int>>&m){
        int n=m.size(),p=m[0].size(),res=0;
        vector<vector<int>>dp(n,vector<int>(p,0));
        for(int i=0;i<n;i++)for(int j=0;j<p;j++)
            res=max(res,dfs(i,j,m,dp));
        return res;
    }
};
int main(){
    vector<vector<int>>m={{9,9,4},{6,6,8},{2,1,1}};
    cout<<Solution().longestIncreasingPath(m);
}
