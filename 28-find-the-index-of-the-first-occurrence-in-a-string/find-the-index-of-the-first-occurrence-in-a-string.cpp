class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(),m=needle.size();
        for(int i=0;i+m<=n;i++){
            if(haystack.compare(i,m,needle) ==0) return i;
        }
        return -1;
    }
};