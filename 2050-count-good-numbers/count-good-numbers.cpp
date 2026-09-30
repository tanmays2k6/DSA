class Solution {
public:
    static const long long MOD = 1000000007;
    long long modPower(long long base, long long exponent) {
        long long result = 1;
 
        while (exponent > 0) {
            
            if (exponent % 2 == 1) {
                result = (result * base) % MOD;
            }
 
            base = (base * base) % MOD;
 
            exponent /= 2;
        }
 
        return result;
    }
    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;
 
        long long oddPositions = n / 2;
 
        long long evenWays = modPower(5, evenPositions);
 
        long long oddWays = modPower(4, oddPositions);
 
        return (evenWays * oddWays) % MOD;
    }
};