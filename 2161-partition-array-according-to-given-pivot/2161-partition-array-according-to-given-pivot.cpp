class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int cntP = 0;
        list<int> l1, l2;
        for(auto it : nums){
            if(it < pivot){
                l1.push_back(it);
            }
            else if(it > pivot){
                l2.push_back(it);
            }
            else{
                cntP++;
            }
        }
        for(int i = 0; i<cntP; i++){
            l1.push_back(pivot);
        }

        int i = 0;
        for(auto it : l1){
            nums[i] = it;
            i++;
        }
        for(auto it : l2){
            nums[i] = it;
            i++;
        }

        return nums;
    }
};