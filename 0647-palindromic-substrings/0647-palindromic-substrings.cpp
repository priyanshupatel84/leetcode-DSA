class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;    
        int n = s.length();


        for(int i = 0; i<n; i++){
            // for odd number of element in palindroom 
            int l = i, r = i;
            while(l>= 0 && r<n && s[l] == s[r]){
                cnt++;
                l--;
                r++;
            }

            l = i, r = i+1;
            while(l >= 0 && r<n && s[l] == s[r]){
                cnt++;
                l--;
                r++;
            }
        }

        return cnt;
    }
};