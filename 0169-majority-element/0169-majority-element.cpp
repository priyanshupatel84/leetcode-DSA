class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore voting algorithm 
        int n = nums.size();
        int ele = 0;
        int cnt = 0;

        for(int i = 0; i<n; i++){
            if(cnt == 0){
                ele = nums[i];
            }
            if(ele = nums[i]){
                cnt++;
            }else{
                cnt--;
            }
        }

        return ele;
        
    }
};