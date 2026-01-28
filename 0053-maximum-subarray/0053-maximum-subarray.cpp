class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;

        int t = 0;
        for(int i = 0; i<n; i++){
            t = t+nums[i];
            ans = max(ans, t);
            if(t < 0){
                t =0;
            }
        }

        return ans;




    }
};