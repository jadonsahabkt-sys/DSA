class Solution {
public:
    string reverseWords(string s) {
        // Step 1: extract words (skip extra spaces)
        vector<string> words;
        int n = s.size();
        int i = 0;
         while (i < n) {
            while (i < n && s[i] == ' ') i++;  // skip spaces
            if (i >= n) break;
            
            int start = i;
            while (i < n && s[i] != ' ') i++;
            words.push_back(s.substr(start, i - start));
        }
        
        // Step 2: reverse the words vector and join
        string result;
        for (int j = words.size() - 1; j >= 0; j--) {
            result += words[j];
            if (j != 0) result += ' ';
        }
        
        return result;
    }
};