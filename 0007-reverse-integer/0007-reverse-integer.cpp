class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if(x <0){
            sign = -1;
        }
        int tmp = abs(x);
        long long  num = 0;
        while(tmp > 0){
            num *= 10;
            num += tmp %10;
            tmp /= 10;
        }
        num = num*sign;
        if(num < INT_MIN){
            return 0;
        }else if(num > INT_MAX){
            return 0;
        }

        return (int)num;
    }
};