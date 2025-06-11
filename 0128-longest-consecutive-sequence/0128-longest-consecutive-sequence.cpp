class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1){
            return nums.size();
        }

        set<int> st;
        for(auto it : nums){
            st.insert(it);
        }
        int ans = 0;

        for(auto it : st){
            int ele = it;
            if(st.find(ele-1) == st.end()){
                bool flag = true;
                int cnt = 0;
                while(flag){
                    if(st.find(ele) != st.end()){
                        cnt++;
                        ele++;
                    }else{
                        flag = false;
                    }
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};