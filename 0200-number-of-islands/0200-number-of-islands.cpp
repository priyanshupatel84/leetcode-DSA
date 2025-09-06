class Solution {
public:
    void solve(vector<vector<char>> &grid, vector<vector<int>> &vis, int r, int c, int m, int n){
        if(r < 0 || r >= m || c <0 || c>= n || vis[r][c] == 1 || grid[r][c] == '0'){
            return;
        }
        vis[r][c] = 1;
        solve(grid, vis, r-1, c, m,n);
        solve(grid, vis, r+1, c, m,n);
        solve(grid, vis, r, c-1, m,n);
        solve(grid, vis, r, c+1, m,n);
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));
        int ans = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    solve(grid, vis, i, j, m, n);
                    ans++;
                }
            }
        }

        return ans;
    }
};