class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> cnt(n+1,0);
        cnt[0]=1;
        int odd=0,res=0;
        for(int x:nums){
            odd +=x&1;
            if(odd>=k) res +=cnt[odd-k];
            cnt[odd]++;
        }
        return res;
    }
};