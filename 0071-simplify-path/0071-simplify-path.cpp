class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string dir="";
        for(int i=0;i<=path.size();i++){
            if(i<path.size() && path[i]!='/'){
                dir+=path[i];
            }
            else{
                if(dir=="" || dir=="."){

                }
                else if(dir==".."){
                    if(!st.empty())    st.pop();
                }
                else{
                    st.push(dir);
                }
                dir="";
            }
        }
        string ans="";
        while(!st.empty()){
            ans="/"+st.top()+ans;
            st.pop();
        }
        if(ans.empty()){
            return "/";
        }
        return ans;
    }
};