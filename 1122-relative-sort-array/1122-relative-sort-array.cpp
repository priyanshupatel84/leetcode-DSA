class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        for(auto it : arr1){
            mp[it]++;
        }   
        int n = arr2.size();
        int i = 0;
        for(int j = 0; j<n; j++){
            int ele = arr2[j];
            int k = mp[arr2[j]];
            mp.erase(ele);
            while(k > 0){
                arr1[i] = ele;
                i++;
                k--;
            }
        }

        for(auto it : mp){
            int ele = it.first;
            int k = it.second;
            while(k>0){
                arr1[i] = ele;
                i++;
                k--;
            }
        }

        return arr1;
    }
};