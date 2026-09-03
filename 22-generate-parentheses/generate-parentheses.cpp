class Solution {
public:
    void solve(int open,int close, int n,string current, vector<string>& ans){

        if(open == n && close == n){
            ans.push_back(current);
            return;
        }

        //Add opening bracket
        if(open < n){
            solve(open + 1,close,n,current + "(",ans);
        }

        //Add closing bracket only if valid
        if(close < open){
            solve(open,close+1,n,current+")",ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0,0,n,"",ans);
        return ans;
    }
};