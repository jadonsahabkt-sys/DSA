class Solution {
public:
    
    int findDays(vector<int> &weight,int cap){
        int days =1;
        int load=0;
        for(int i=0;i<weight.size();i++){
            if(weight[i] + load>cap){
                days+=1;
                load=weight[i];
            }
            else {
                load+=weight[i];
            }
        }
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int numberOfDays=findDays(weights,mid);
            if(numberOfDays <= days){
                high=mid-1;
            }
            else
             {
                low=mid+1;
                
            }
          
        }
        return low;
    }
};