class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),parent(n,-1);
        int maxLen=1,maxIdx=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1
                >dp[i]){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
            if(dp[i]>maxLen){
                maxLen=dp[i];
                maxIdx=i;
            }
        }
            vector<int> res;
            for(int i=maxIdx;i!=-1;i=parent[i])
            res.push_back(nums[i]);
            return res;
      
    }
};