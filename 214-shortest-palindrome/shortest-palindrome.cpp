class Solution {
public:
    string shortestPalindrome(string s) {
        string rev(s.rbegin(),s.rend());
        string t=s +"#"+rev;
        int n=t.size();
        vector<int>lps(n,0);
        for(int i=1;i<n;i++){
            int j=lps[i-1];
            while(j>0 && t[i]!=t[j]) j=lps[j-1];
            if(t[i]==t[j]) j++;
            lps[i]=j;
        }
        int palLen=lps[n-1];
        return rev.substr(0,s.size()-palLen)+s;
    }
};