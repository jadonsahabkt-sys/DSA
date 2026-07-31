class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int> temp;
        int i;
        for(i=n-k;i<n;i++){
            temp.push_back(nums[i]);
        }
        for(i=n-1;i>=k;i--){
            nums[i]=nums[i-k];
        }

        for(i=0;i<k;i++){
            nums[i]=temp[i];
        }
        
        
    }
};