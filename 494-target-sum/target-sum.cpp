class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>sum || (target + sum)% 2 != 0) return 0;
        int P=(target +sum )/2;
        vector<int>dp(P+1,0);
        dp[0]=1;
        for(int x:nums){
        for(int j=P;j>=x;--j){
             dp[j] += dp[j-x];
        }
        }
        return dp[P];
    }
};