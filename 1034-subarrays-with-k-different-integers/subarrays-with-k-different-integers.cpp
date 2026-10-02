class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        vector<int>freq(nums.size()+1,0);
        int left=0,distinct=0,res=0;
        for(int right=0;right<nums.size();right++){
            if(freq[nums[right]]++ == 0) distinct++;
            while(distinct>k){
                if(--freq[nums[left]]==0) distinct--;
                left++;
            }
            res +=right-left+1;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums,int k){
        return atMost(nums,k)-atMost(nums,k-1);
    }
};