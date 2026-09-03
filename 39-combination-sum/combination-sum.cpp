class Solution {
public:
    void solve(vector<int>& candidates, int target,int index,vector<int>& current, vector<vector<int>>& ans){
        // target reached
        if(target == 0){
            ans.push_back(current);
            return;
        }

        // Try every candidates from index onwards
        for(int i=index;i<candidates.size();i++){

            // Candidate is too large
            if(candidates[i] > target)
               continue;

            // Choose
            current.push_back(candidates[i]);

            //Same i because we can reuse the same number
            solve(candidates,target-candidates[i],i,current,ans);

            //backtrack
            current.pop_back();  
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>current;

        solve(candidates,target,0,current,ans);

        return ans;
    }
};