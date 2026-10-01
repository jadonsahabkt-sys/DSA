class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>freq;
        int left=0;
        int maxFreq=0;
        int ans=0;
        for(int right =0;right<s.size();right++){
            freq[s[right]]++;
           maxFreq=max(maxFreq,freq[s[right]]);
           int replacements=(right -left +1)-maxFreq;
           
           while(replacements>k){
            freq[s[left]]--;
            left++;
            replacements=(right-left+1)-maxFreq;
           }
           ans=max(ans,right-left+1);
        }
        return ans;
    }

};