class Solution {
public:
    int minSensors(int n, int m, int k) {
        long long side=2*k+1;
        long long x=(n+side-1)/side;
        long long y=(m+side-1)/side;
        return (int)x*y;
    }
};