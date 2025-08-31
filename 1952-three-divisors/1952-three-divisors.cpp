class Solution {
public:
    bool isThree(int n) {
        if(n == 4) return true;
        int cnt = 0;
        for(int i = 2; i<= n/2; i++){
            if(n%i == 0){
                cnt++;
                if(cnt>1) return false;
            }
        }

        return cnt == 1;
    }
};