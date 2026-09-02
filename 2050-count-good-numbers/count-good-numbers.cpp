class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long base, long long exp){
        long long ans =1;
        while(exp >0){
            if(exp % 2 ==1){
                ans=(ans * base)% MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long evenPosition = (n+1)/2;
        long long oddPosition = n/2;

        long long evenWays = power(5,evenPosition);
        long long oddWays = power(4,oddPosition);

        return (evenWays * oddWays) % MOD;
        
    }
};