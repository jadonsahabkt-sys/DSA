class Solution {
public:
    string frequencySort(string s) {
         
         unordered_map<char, int> freq;

        // Count frequency
        for(char c: s){
            freq[c]++;
        }

        // store{frequency,charater}
        vector<pair<int,char>> v;
        for(auto it:freq){
            v.push_back({it.second,it.first});
        }        

        // sort by frequency in decreasing order
        sort(v.begin(),v.end(),greater<pair<int,char>>());

        // build answer
        string ans;
        for(auto p:v){
            int count = p.first;
            char ch=p.second;
            while(count--){
                ans+=ch;
            }
        }
        return ans;
    }
};