class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);

        //Count frequence
        for(char ch :s){
            freq[ch -'a']++;
        }

        string left="";
        string mid="";

        //Build left half

        for(int i=0;i<26;i++){
            left.append(freq[i]/2,char('a'+i));

            if(freq[i]%2==1)
            mid=char('a'+i);
        }

        //Right half
        string right=left;
        reverse(right.begin(),right.end());

        return left+mid+right;
        
    }
};