class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if(n == 0 || n == 1){
            return n;
        }
        int prevInd = 0;

        for(int i = 1; i<n; i++){
            if(nums[prevInd] != nums[i]){
                nums[++prevInd] = nums[i];

            }
        }
        return prevInd+1;
    }
};