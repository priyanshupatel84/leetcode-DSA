class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int n = s.length();
        int l = 0;
        int maxvowel = 0;
        int temp =0;
        for(int r= 0; r<n; r++){
            if(isVowel(s[r])){
                temp++;
            }

            if((r-l +1) == k){
                maxvowel = max(maxvowel, temp);
                if(isVowel(s[l])){
                    temp--;
                }
                l++;
            }
        }

        return maxvowel;
    }
};