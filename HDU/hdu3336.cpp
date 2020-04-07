#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=2e5+5;
static const int mod=10007;
char s[maxn];
int ne[maxn];
void getNext(){
    int i=0,j=-1;
    ne[0]=-1;
    int le=strlen(s);
    while(i<le){
        if(j==-1||s[i]==s[j]) ne[++i]=++j;
        else j=ne[j];
    }
}
int dp[maxn];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d%s",&n,s);
        getNext();
        dp[0]=0;
        int ans=0;
        for(int i=1;i<=n;++i){
            dp[i]=(dp[ne[i]]+1)%mod;
            ans=(ans+dp[i])%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}