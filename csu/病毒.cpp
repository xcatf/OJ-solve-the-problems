#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int N=1e3+5;
int a[N],b[N],dp[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d",&n);
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        scanf("%d",&m);
        for(int i=1;i<=m;++i) scanf("%d",&b[i]);
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<=n;++i){
            int cnt=0;
            for(int j=1;j<=m;++j){
                if(a[i]>b[j]&&cnt<dp[j]) cnt=dp[j];
                if(a[i]==b[j]) dp[j]=cnt+1;
                ans=max(ans,dp[j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}