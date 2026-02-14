class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101, vector<double> (101, 0.0));
        double p = (double)poured;
        dp[1][1] = p;

        for(int i = 2; i<=100; i++){
            for(int j = 1; j<=100; j++){
                double l = dp[i-1][j-1];
                double r = dp[i-1][j];

                if(l >1){
                    dp[i][j] = (l-1)/2;
                }
                if(r>1){
                    dp[i][j] += (r-1)/2;
                }
            }
        }

        
        if(dp[query_row+1][query_glass+1] > 1){
            return (double)1;
        }
        else{
            return dp[query_row+1][query_glass+1];
        }
    }
};