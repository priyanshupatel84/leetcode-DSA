class Solution {
public:
    int reverseBits(int n) {
        string b = "";
        int num = n;

        for(int i = 0; i<32; i++){
            if(num&1){
                b +="1";
            }else{
                b += "0";
            }
            num = num>>1;
        }

        // cout <<" string : " << b<< endl;
        reverse(b.begin(), b.end());
        int ans = 0;
        for(int i = 0; i<b.length(); i++){
            if(b[i] == '1'){
                int x = 1<<i;
                ans += x;
            }
        }
        return ans;
    }
};