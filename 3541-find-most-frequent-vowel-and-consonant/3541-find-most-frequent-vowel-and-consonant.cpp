class Solution {
public:
    int maxFreqSum(string s) {
    int vof = 0;
    int cof = 0;
    vector<int> arr(26, 0);

    for(auto it : s){
        int ind = it-'a';
        if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u'){
            arr[ind]++;
            vof = max(vof, arr[ind]);
        }else{
            arr[ind]++;
            cof = max(cof, arr[ind]);
        }
    }
        
        return vof + cof;
    }
};