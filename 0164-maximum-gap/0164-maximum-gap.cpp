class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        if(n <=1){
            return ans;
        }

        priority_queue<int> pq;
        for(int i = 0; i<n; i++){
            pq.push(nums[i]);
        }

        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            ans = max(ans, a-pq.top());
        }

        return ans;
    }
};