class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        if(n == 3){
            int sum = nums[0]+nums[1]+nums[2];
            return sum;
        }
        
        int sum = INT_MAX;
        for(int i = 1; i<n-1; i++){
            int ans = nums[i];
            for(int j = i+1; j<n; j++){
                ans += nums[j];
                sum = min(sum , ans);
                ans -= nums[j];
            }
        }
        sum += nums[0];
        return sum;
    }
};