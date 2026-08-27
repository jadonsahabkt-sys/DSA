class Solution {
public:
   int getMinCount(int freq[26]){
        int minCount = INT_MAX;
        for(int i=0;i<26;i++){
            if(freq[i] != 0){
                minCount = min(minCount,freq[i]);
            }
        }
        return minCount;
    }

    int getMaxCount(int freq[26]){
        int maxCount = 0;
        for(int i=0;i<26;i++){
            maxCount = max(maxCount,freq[i]);
        }
        return maxCount;
    }

    int beautySum(string s) {
        int sum=0;
        for(int i=0;i<s.length();i++){
            int freq[26] = {0}; //0
            for(int j=i;j<s.length();j++){
                freq[s[j] - 'a']++;
                int beauty = getMaxCount(freq) - getMinCount(freq);
                sum +=beauty;
            }
        }
        return sum;
    }
};