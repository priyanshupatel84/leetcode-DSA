class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char, int> mp;
        int cnt = 0;
        int n = text.length();

        for(auto it : brokenLetters){
            mp[it]=1;
        }

        int i = 0 ;
        while(i<n){
            char ch = text[i];
            if(isalpha(ch)){
                while(isalpha(text[i])){
                    i++;
                }
                cnt++;
            }
            i++;
        }

        i = 0 ;
        while(i<n){
            if(mp[text[i]] == 1){
                while(isalpha(text[i])){
                    i++;
                }
                cnt--;
            }
            i++;
        }

        return cnt;
    }
};