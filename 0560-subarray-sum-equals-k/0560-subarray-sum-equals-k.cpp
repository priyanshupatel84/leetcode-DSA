class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int ans = 0;
        int n = nums.size();

        mp[0] = 1;

        for(int i = 0; i<n; i++){
            sum += nums[i];
            int comp = sum - k;

            if(mp.find(comp) != mp.end()){
                ans += mp[comp];
            }
            mp[sum]++;
        }

        return ans;
    }
};