class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int i = 1, j = 0;
        int cnt = 1, ans = 0;
        int n = colors.size();

        while(j<n){
            if(colors[i%n] != colors[(i-1)%n]){
                i++;
                cnt++;
            }else{
                j= i;
                cnt = 1;
                i++;
            }

            if(cnt == k){
                ans++;
                j++;
                cnt--;
            }
        }

        return ans;
    }
};