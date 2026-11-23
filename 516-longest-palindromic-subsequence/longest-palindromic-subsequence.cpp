class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t(s.rbegin(),s.rend());
        int n=s.size();
        vector<int> prev(n+1,0),curr(n+1,0);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1])
                  curr[j]=prev[j-1]+1;
                else 
                curr[j]=max(prev[j],curr[j-1]);

            }
            swap(prev,curr);
        }
        return prev[n];
    }
};