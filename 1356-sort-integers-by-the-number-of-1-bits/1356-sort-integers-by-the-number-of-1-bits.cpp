class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // vector<pair<int, int>> vis;
        // for(auto it : arr){
        //     int x = __builtin_popcount(it);
        //     vis.push_back({it, x});
        // }
        // sort(vis.begin(), vis.end(), [](const auto&a, const auto&b){
        //     if(a.second == b.second){
        //         return a.first < b.first;
        //     }
        //     return a.second < b.second;
        // });
        // vector<int> ans;
        // for(auto it: vis){
        //     ans.push_back(it.first);
        // }
        // return ans;


        // better code 
         sort(arr.begin(), arr.end(), [](int a, int b) {
            int ca = __builtin_popcount(a);
            int cb = __builtin_popcount(b);
            return ca != cb ? ca < cb : a < b;
        });

        return arr;
    }
};