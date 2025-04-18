class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int> (n, 0));

        int m = queries.size();
        for(int i = 0; i<m; i++){
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];

            for(int l = r1; l<=r2; l++){
                for(int k = c1; k<= c2; k++){
                    mat[l][k] += 1;
                }
            }
        }

        return mat;
    }
};