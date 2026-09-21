class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string dir;
        while(getline(ss,dir,'/')){
            // current directory or empty part
            if(dir == ""|| dir=="."){
                continue;
            }
            // parent directory
            if(dir == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            // normal directory 
            else {
                st.push(dir);
            }
        }
        //construct answer
        string ans="";
        while(!st.empty()){
            ans="/"+st.top()+ans;
            st.pop();
        }
        //Root directory
        if(ans==""){
            return"/";
        }

        return ans;
    }
};