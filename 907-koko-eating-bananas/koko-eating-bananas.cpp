class Solution {
public:
     int findMax(vector<int> &v){
        int maxi = INT_MIN;
        int n = v.size();
        for(int i = 0; i < n; i++){
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }
    
    long long calculateTotalHours(vector<int> &v, long long hourly){
        long long totalH = 0;
        int n = v.size();
        for(int i = 0; i < n; i++){
            totalH += ((long long)v[i] + hourly - 1) / hourly;
        }
        return totalH;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1, high = findMax(piles);
        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long totalH = calculateTotalHours(piles, mid);
            if(totalH <= h){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return (int)low;
    }
        
    
};