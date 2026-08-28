class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.length();

        //1. skip leading space 
        while(i<n && s[i] == ' '){
            i++;
        }
        //2. check sign
        int sign=1;
        if(i<n && s[i] == '-'){
            sign=-1;
            i++;
        }
        else if(i<n && s[i] == '+'){
            i++;
        }
        //3.Convert digits
        long long num =0;
        while(i<n && isdigit(s[i])){
            int digit=s[i]-'0';

            num=num * 10 +digit;
            
            // check overflow
            if(sign == 1 && num >INT_MAX){
                return INT_MAX;
            }
            if(sign== -1 && num > 2147483648LL ){
                return INT_MIN;
            }
            i++;
        }
           return (sign * num);
    }
};