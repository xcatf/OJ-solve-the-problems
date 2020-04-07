#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e4 + 5;
int x[11],y[11];
int d[11][11];
bool v[11];
int k;
ll ans;
void dfs(int cnt,int u,ll now){
    if(cnt==k){
        ans=min(ans,now+d[u][0]);
        return ;
    }
    if(now>=ans) return ; 
    for(int i=1;i<=k;++i){
        if(!v[i]){
            v[i]=1;
            dfs(cnt+1,i,now+d[u][i]);
            v[i]=0;
        }
    }
}
int main(){
    scanf("%d%d%d",&x[0],&y[0],&k);
    for(int i=1;i<=k;++i) scanf("%d%d",&x[i],&y[i]);
    for(int i=0;i<k;++i){
        for(int j=i+1;j<=k;++j){
            d[i][j]=d[j][i]=abs(x[i]-x[j])+abs(y[i]-y[j]);
        }
    }
    ans=(1ll<<34);
    dfs(0,0,0);
    printf("%lld\n",ans);
    return 0;
}