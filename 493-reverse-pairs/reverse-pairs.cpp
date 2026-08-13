class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);

    }

    private:
    int mergeSort(vector<int>& nums,int left,int right){
        if(left>=right) return 0;
        int mid=left + (right -left) /2;
        int count=mergeSort(nums,left,mid) + mergeSort(nums,mid+1,right);

        //Count reverse pairs across the two sorted halves
        int j=mid+1;
        for(int i=left;i<=mid;i++){
            while(j<=right && (long long)nums[i]>2LL*nums[j]) j++;
            count+=j-(mid+1);
        }

        //Standard merge step
        vector<int> merged;
        merged.reserve(right-left +1);
        int p1=left,p2=mid+1;
        while(p1<=mid && p2<=right){
            if(nums[p1]<=nums[p2]) merged.push_back(nums[p1++]);
            else merged.push_back(nums[p2++]);
        }
        while(p1<=mid) merged.push_back(nums[p1++]);
        while(p2<=right) merged.push_back(nums[p2++]);

        for(int i=left;i<=right;i++) nums[i]=merged[i-left];
        return count;
    }
};