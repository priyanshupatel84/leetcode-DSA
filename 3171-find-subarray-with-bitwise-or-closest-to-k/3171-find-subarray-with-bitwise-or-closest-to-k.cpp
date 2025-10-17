class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int res = INT_MAX;
        unordered_set<int> s;
        
        for(int i:nums) {
            unordered_set<int> s2;
            for(int j:s) {
                int x = i|j;
                s2.insert(x);
                res = min(res, abs(k-x));
            }
            s2.insert(i);
            res = min(res, abs(k-i));
            s = s2;
        }
        return res;
    }
};