class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for(auto it : s){
            mp[it]++;
        }
        int n = order.size();
        int j = 0;
        for(int i = 0; i<n; i++){
            char ch = order[i];
            int k = 0;
            if(mp[ch]){
                k = mp[ch];
                mp.erase(ch);
            }
            while(k > 0 ){
                s[j] = ch;
                j++;
                k--;
            }
        }

        for(auto it : mp){
            char ch = it.first;
            int k = it.second;
            while(k>0){
                s[j] = ch;
                j++;
                k--;
            }
        }
        return s;

    }
};