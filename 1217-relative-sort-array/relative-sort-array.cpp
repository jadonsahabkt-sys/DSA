class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> freq(1001,0);
        //count frequency of element
        for(int x:arr1){
            freq[x]++;

        }
        vector<int>ans;
        //Put element according to arr2 order
        for(int x : arr2){
            while(freq[x]>0){
                ans.push_back(x);
                freq[x]--;
            }
        }
        //Put remaing element in ascending order
        for(int x=0;x<=1000;x++){
            while(freq[x]>0){
                ans.push_back(x);
                freq[x]--;
            }
        }
        return ans;
    }
};