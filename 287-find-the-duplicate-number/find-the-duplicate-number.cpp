class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow=nums[0];
        int fast=nums[0];
        //find the meeting point

        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        //find the entrance of the cycle
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
        
    }
};