#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int p[maxn],a[maxn],dp[maxn],ans[maxn];
int main(){ 
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
            dp[i]=INT_MAX;
        }
        int maxl=0;
        for(int i=1;i<=n;++i){
            int pos=lower_bound(dp+1,dp+n+1,a[i])-dp;
            dp[pos]=a[i];
            p[i]=pos;
            maxl=max(pos,maxl);
        }
        int now=maxl,pre=INT_MAX;
        for(int i=n;i>=1&&now;--i){
            if(p[i]==now&&a[i]<pre){
                pre=a[i];
                ans[now--]=a[i];
            }
        }
        printf("%d\n",maxl);
        for(int i=1;i<=maxl;++i) printf("%d%c",ans[i],i==maxl?'\n':' ');
    }
    return 0;
}