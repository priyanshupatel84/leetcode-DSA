class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int n = right;
        vector<int> isPrime(33, 1);
        isPrime[0] = 0; 
        isPrime[1] = 0; 
        for(int i = 2; i*i<=32; i++){

            if(isPrime[i]){
                for(int j = i*i; j<=32; j+=i){
                    isPrime[j] = 0;
                }
            }
        }

        int cnt = 0;
        for(int i = left; i<= right; i++){
            if(isPrime[__builtin_popcount(i)]){
                cnt++;
            }
        }

        return cnt;
    }
};