class Solution {
public:
    // Helper function: checks if we can make at least 'm' bouquets
    // of 'k' adjacent roses each, by the given 'day'
    bool canMake(vector<int>& bloomDay, int day, int k, int m) {
        int n = bloomDay.size();
        int streak = 0;      // count of consecutive bloomed roses
        int bouquets = 0;    // bouquets made so far

        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                streak++;
                if (streak == k) {
                    bouquets++;
                    streak = 0;   // reset streak after using k roses for a bouquet
                }
            } else {
                streak = 0;      // adjacency broken, unbloomed rose
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        // Quick infeasibility check
        if ((long long)m * (long long)k > n) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, mid, k, m)) {
                ans = mid;       // mid works, try to find an earlier day
                high = mid - 1;
            } else {
                low = mid + 1;   // mid doesn't work, need a later day
            }
        }

        return ans;
    }
};


        
    
