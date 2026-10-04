class Solution {
    long long contribution(vector<int>& a,bool isMax){
        int n=a.size();
        vector<int>st;
        long long total=0;
        for(int i=0;i<=n;i++){
            long long cur =(i==n) ? (isMax?LLONG_MAX : LLONG_MIN) : a[i];
            while(!st.empty() && (isMax ? a[st.back()]<cur: a[st.back()]>cur)){
             
             int mid=st.back();st.pop_back();
             int left=st.empty() ?-1:st.back();
             total +=(long long)a[mid] *(mid - left)*(i-mid);
            }
            st.push_back(i);
        }
        return total;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return contribution(nums,true)-contribution(nums,false);
    }
};