class Solution {
public:
    bool isValid(vector<int>& nums,int mid,int k){
        int count=1;
        long long sum = 0;
        for(int x : nums){
            if(sum + x > mid){
                count++;
                sum=x;
                if(count > k) return false;
            } else{
                sum+=x;
            }
        }
        return count <=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        long long high = 0;
        for(int x : nums) high +=x;

        int ans = high;
        while(low <= high){
            int mid = low + (high -low)/2;
            if(isValid(nums,mid,k)){
                ans = mid;
                high = mid-1; 

            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
};