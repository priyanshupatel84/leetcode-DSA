class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        if(n <2)return 0;

        int buy = prices[0];
        for(int i = 1; i<n; i++){
            int sell = prices[i];
            if(sell>= buy){
                ans = max(ans, (sell-buy));
            }else{
                buy = sell;
            }
        }

        return ans;
    }
};