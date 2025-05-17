class Solution {
public:
# define ll long long
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        map<ll, ll> freq;
        for(int i = 0; i<n; i++){
            freq[power[i]]++;
        }

        unordered_map<int, ll> dp;
        ll ans = 0, prevEl,backEl = 0;
        
        for(auto [el, fr] : freq){
            auto backIt = freq.lower_bound(el-2);
            if(backIt != freq.begin()) backEl = (*(--backIt)).first;
            dp[el] = max(dp[prevEl], el*fr +dp[backEl]);
            ans = max(ans, dp[el]);

            prevEl = el;
        }
        
        return ans;
    }
};