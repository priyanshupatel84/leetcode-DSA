class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int l = 0;
        int sum = 0;
        int cnt = 0;

        for(int r = 0; r<n; r++){
            sum += arr[r];
            if((r-l+1) == k){
                if((sum / k) >= threshold) cnt++;
                sum -= arr[l];
                l++;
            }
        }
        return cnt;
    }
};