class Solution {
public:
    long long coloredCells(int n) {
        // this is like ap 
        long long N = n;
        long long ans = 1+(4+ (N-1)*4)*(N-1)/2;

        return ans;
    }
};