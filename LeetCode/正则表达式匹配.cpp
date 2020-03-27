class Solution {
public:
    bool isMatch(string s, string p) {
        if(s==""&&p=="") return 1;
        int ls=s.length(),lp=p.length();
        bool dp[ls+1][lp+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<lp;++i){
            if(p[i]=='*'&&dp[0][i-1]) dp[0][i+1]=1;
        }
        for(int i=0;i<ls;++i){
            for(int j=0;j<lp;++j){
                if(s[i]==p[j]||p[j]=='.') dp[i+1][j+1]=dp[i][j];
                if(j&&p[j]=='*'){
                    if(p[j-1]!=s[i]&&p[j-1]!='.') dp[i+1][j+1]=dp[i+1][j-1];
                    else{
                        dp[i+1][j+1]=dp[i+1][j]|dp[i][j+1]|dp[i+1][j-1];
                    }
                }
            }
        }
        return dp[ls][lp];
    }
};