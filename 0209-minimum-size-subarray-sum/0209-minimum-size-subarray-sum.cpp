class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i =0, j = 0;
        int n = nums.size();
        int ans = INT_MAX;

        int sum = 0;
        while(i <= j && i < n && j < n){
            sum += nums[j];
            if(sum >= target){
                ans = min(ans, j-i+1);
                while(sum >= target){
                    sum -= nums[i];
                    i++;
                    if(sum >= target) ans = min(ans, j-i+1);
                }
            }
            j++;
        }

        if(ans == INT_MAX) return 0;
        return ans;
    }
};