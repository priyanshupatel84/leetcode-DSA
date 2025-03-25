class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // main idea is to generate a key 
        unordered_map<string, vector<string>> mp;

        for(auto s : strs){
            string key  = s;
            sort(key.begin(), key.end());

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};