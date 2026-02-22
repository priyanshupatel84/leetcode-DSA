class Solution {
public:
    int binaryGap(int n) {
        int gap = 0;
        int l = -1;
        for(int i=0;i<32; i++){
            if(n&1 && l ==-1){
                l = i;
            }else if(n&1 && l !=-1){
                gap = max(gap, (i-l));
                l = i;
            }

            n >>=1;
        }


        return gap;
    }
};