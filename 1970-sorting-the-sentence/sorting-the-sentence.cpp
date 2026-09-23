class Solution {
public:
    string sortSentence(string s) {
        vector<string>words(10);
        string word = "";
        for(int i=0;i<=s.size();i++){
            if(i==s.size() || s[i]== ' ') {
                int pos = word.back()-'0';
                word.pop_back();
                words[pos]=word;
                word="";
            }
            else{
                word+=s[i];

            }
        }
        string ans="";
        for(int i=1;i<=9;i++){
            if(words[i] != ""){
                if(ans!="")
                ans+=" ";
                ans+=words[i];
            }
        }
        return ans;
    }
};