#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int n,w;
int v[32];
ll ans;
ll quick(int a,int b){
    ll res=1;
    while(b){
        if(b&1) res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
int dfs(int i,int now){
    if(now<0) return 0;
    if(i==0){
        if(v[i]>now) return 1;
        return 2;
    }
    return dfs(i-1,now-v[i])+dfs(i-1,now);
}
int main(){
    scanf("%d%d",&n,&w);
    ll cnt=0;
    for(int i=0;i<n;++i){
        scanf("%d",&v[i]);
        cnt+=v[i];
    }
    if(cnt<=w) ans=quick(2,n);
    else ans=dfs(n-1,w);
    printf("%lld\n",ans);
    return 0;
}