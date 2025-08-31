class Solution {
    vector<pair<int,int>>dir = {{1,0},{0,1}};
    int n,m;
    const int mod = 1e9+7;
    int dp[501][501][3];
    int solve(vector<vector<int>>&grid,int i,int j,int currDir){
        if(i == n-1 && j == m-1) return 1;
        if(dp[i][j][currDir+1] != -1) return dp[i][j][currDir+1];
        int ans = 0;
        if(grid[i][j] == 1){
            int x = i+dir[currDir].first;
            int y = j+dir[currDir].second;
            if(x >= 0 && x < n && y >= 0 && y < m){
                ans = (solve(grid,x,y,!currDir)+ans)%mod;
            }
        }
        else{
            for(int k = 0;k<2;k++){
            int dx = dir[k].first;
            int dy = dir[k].second;
            int x = i+dx;
            int y = j+dy;
            if(x >= 0 && x < n && y >= 0 && y < m){
                    if(grid[x][y] == 1){
                        ans = (ans+solve(grid,x,y,!k))%mod;
                    }
                    else ans = (ans+solve(grid,x,y,k))%mod;
                }
            }
        }
        return dp[i][j][currDir+1] = ans;
    }
public:
    int uniquePaths(vector<vector<int>>&grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,-1);
    }
};