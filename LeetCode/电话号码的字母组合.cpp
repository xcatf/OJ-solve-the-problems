class Solution {
public:
    char s[10][5]={"","!@#","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string str;
    vector<string>res;
    void dfs(int id,string digits,int ls){
        if(id>=ls){
            res.push_back(str);
            return ;
        }
        int p=digits[id]-'0';
        for(int i=0;i<strlen(s[p]);++i){
            str+=s[p][i];
            dfs(id+1,digits,ls);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return res;
        int ls=digits.length();
        dfs(0,digits,ls);
        return res;
    }
};