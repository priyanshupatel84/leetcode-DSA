class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        // mono tonic stack se hoga 
        vector<int> ng(n, -1);
        vector<int> pg(n, -1);
        // next greater 
        stack<int> st;
        int i = n-1;
        while(i>= 0){
            if(st.empty()){
                st.push(i);   
                i--;
            }else if(nums[i] < nums[st.top()]){
                ng[i] = st.top();
                st.push(i);
                i--;
            }else if(nums[i] > nums[st.top()]){
                st.pop();
            }
        }
        while(!st.empty()){
            st.pop();
        }

        i = 0;
        while(i < n){
            if(st.empty()){
                st.push(i);   
                i++;
            }else if(nums[i] < nums[st.top()]){
                pg[i] = st.top();
                st.push(i);
                i++;
            }else if(nums[i] > nums[st.top()]){
                st.pop();
            }
        }


        for(int i = 0; i<n; i++){
            int r = ng[i];
            int l = pg[i];

            if(l != -1 && r != -1 && (r-l+1)>= 3){
                ans++;
            }
        }


        return ans;
    }
};