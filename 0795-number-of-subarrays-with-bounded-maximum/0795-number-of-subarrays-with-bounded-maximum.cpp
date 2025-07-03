class Solution {
public:
    int subarrays(vector<int>& nums , int bound){
        int count = 0, curr = 0;
        for(int i = 0, n = nums.size(); i < n; ++i){
            if(nums[i] < bound) count += ++curr;
            else curr = 0;
        }
        return count;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return subarrays(nums , right + 1) - subarrays(nums , left);
    }
};