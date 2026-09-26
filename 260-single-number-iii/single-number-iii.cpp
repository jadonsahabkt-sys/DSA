class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorAll=0;
        //step1: XOR all number
        for(int n: nums){
            xorAll ^=n;
        }
        //step2 : Find rightmost set bit
        long long  diff = xorAll & (-xorAll);
        int a=0;
        int b=0;
        //step:3 Divide number into two groups 
        for(int n : nums){
            if(n & diff){
                a^=n;
            } else {
                b ^=n;
            }
        }
        return {a,b};
    }
};