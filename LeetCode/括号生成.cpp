class Solution {
public:
    vector<string>res;
    string str;
    void dfs(int l,int r){
        if(l==0&&r==0){
            res.push_back(str);
            return ;
        }
        if(l>0&&r>0){
            str+="(";
            dfs(l-1,r);
            str.pop_back();
        }
        if(r>l&&r>0){
            str+=")";
            dfs(l,r-1);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(n,n);
        return res;
    }
};