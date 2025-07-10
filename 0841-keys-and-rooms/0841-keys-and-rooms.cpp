class Solution {
public:
    void dfs(int node, vector<int> & vis, vector<vector<int>>& rooms, int &cnt){
        vis[node] = 1;
        cnt++;

        for(auto it : rooms[node]){
            if(!vis[it]){
                dfs(it, vis, rooms, cnt);
            }
        }
        return;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int cnt = 0;
        vector<int> vis(n, 0);

        dfs(0, vis, rooms, cnt);
        if( cnt != n) return false;
        return true;
    }
};