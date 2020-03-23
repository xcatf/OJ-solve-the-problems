class Solution {
public:
    string longestPalindrome(string s) {
        int le=s.length();
        bool dp[le+5][le+5];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<le;++i)dp[i][i]=1;
        int start=0,maxl=1;
        for(int i=1;i<le;++i){
            for(int j=0;j<i;++j){
                if(s[j]==s[i]){
                    if(i-j+1<=3) dp[j][i]=1;
                    else dp[j][i]=dp[j+1][i-1];
                }
                if(dp[j][i]){
                    if(maxl<i-j+1){
                        start=j;
                        maxl=i-j+1;
                    }
                }
            }
        }
        return s.substr(start,maxl);
    }
};