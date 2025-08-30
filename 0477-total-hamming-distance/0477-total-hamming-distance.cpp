class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        // int ans = 0;
        // int n = nums.size();
        // for(int i = 0; i<n; i++){
        //     for(int j = i+1; j<n; j++){
        //         ans += __builtin_popcount(nums[i]^nums[j]);
        //     }
        // }
        // return ans;

        int n = nums.size();
        int total = 0;
        for(int bit = 0; bit<32; bit++){
            int countone = 0;
            for(auto it : nums){
                countone += (it>>bit) &1;
            }
            int countzero = n-countone;
            total += countzero * countone;
        }
        return total;
    }
};