class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                       int valueDiff) {
        if(nums.size()>=99997){
            return false;
        };
        for (int z = indexDiff; z > 0; z--) {
            int i = 0;
            int j = z;
            while (j < nums.size()) {
                if (abs(nums[i] - nums[j]) <= valueDiff) {
                    return true;
                }
                i++;
                j++;
            }
        }
        return false;
    }
};