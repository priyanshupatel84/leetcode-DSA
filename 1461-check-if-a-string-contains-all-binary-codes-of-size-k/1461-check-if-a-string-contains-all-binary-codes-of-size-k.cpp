class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        unordered_map<int, bool> mp;
        for(int i = 0; i<=n-k; i++){
            string x = s.substr(i, k);
            int a = stoi(x, nullptr,2);
            mp[a] = true;
        }

        int num = pow(2, k);
        for(int i = 0; i<num; i++){
            if(!mp[i]){
                return false; 
            }
        }
        return true;
    }
};