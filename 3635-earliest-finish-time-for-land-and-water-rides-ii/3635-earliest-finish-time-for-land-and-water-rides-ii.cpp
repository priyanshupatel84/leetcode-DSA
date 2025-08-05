class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int minEnd = INT_MAX;

        // land first
        for(int i = 0; i<n; i++){
            minEnd = min(minEnd, landStartTime[i] + landDuration[i]);
        }
        for(int i = 0; i<m; i++){
            ans = min(ans, max(minEnd, waterStartTime[i]) + waterDuration[i]);
        }


        // water first
        minEnd = INT_MAX;
        for(int i = 0; i<m; i++){
            minEnd = min(minEnd, waterStartTime[i] + waterDuration[i]);
        }
        for(int i = 0; i<n; i++){
            ans = min(ans, max(minEnd, landStartTime[i]) + landDuration[i]);
        }

        return ans;
    }
};