class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c2:s){
            if(st.empty()) st.push(c2);
            else{
                char c1=st.top();
                if(c1=='['&&c2==']'||c1=='('&&c2==')'||c1=='{'&&c2=='}') st.pop();
                else st.push(c2);
            }
        }
        return st.empty();
    }
};