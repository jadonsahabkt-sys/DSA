class Solution {
public:
    int findMaxIndex(vector<vector<int>>& mat, int n, int col) {
        int maxValue = -1;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (mat[i][col] > maxValue) {
                maxValue = mat[i][col];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;   // binary search on columns

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxRow = findMaxIndex(mat, n, mid);

            int left  = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int right = (mid + 1 < m)  ? mat[maxRow][mid + 1] : -1;

            if (mat[maxRow][mid] > left && mat[maxRow][mid] > right) {
                return {maxRow, mid};
            } else if (right > mat[maxRow][mid]) {
                low = mid + 1;    // peak is to the right
            } else {
                high = mid - 1;   // peak is to the left
            }
        }
        return {-1, -1};
    }
};


        
    
