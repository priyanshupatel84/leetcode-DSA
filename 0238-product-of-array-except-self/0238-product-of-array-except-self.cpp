class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro = 1;
        int cnt0 = 0;
        int n = nums.size();
        vector<int> ans(n, 0);

        for(int i = 0; i<n; i++){
            if(nums[i] != 0){
                pro *= nums[i];
            }else{
                cnt0++;
            }
        }

        if(cnt0 > 1) return ans;

        for(int i = 0; i<n; i++){
            if(nums[i] == 0 && cnt0 == 1){
                ans[i] = pro;
                return ans;
            }else if(cnt0 < 1){
                ans[i] = pro/nums[i];
            }
        }

        return ans;
    }
};