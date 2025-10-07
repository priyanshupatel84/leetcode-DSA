class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0, r = 0;
        int cnt = 0;
        unordered_map<char, int>mp;

        while(r<n){
            if(mp[s[r]] > 0){
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
            else{
                mp[s[r]]++;
                r++;
                int temp = mp.size();
                cnt = max(cnt, temp);
            }
        }

        return cnt;
    }
};