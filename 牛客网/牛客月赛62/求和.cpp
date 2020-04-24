#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e6+5;
ll c[maxn];
int a[maxn],l[maxn],r[maxn],n,tot;
vector<int>e[maxn];
int low(int x){return x&-x;}
void add(int x,int v){for(;x<=tot;x+=low(x)) c[x]+=v;}
ll sum(int x){ll ans=0; for(;x;x-=low(x)) ans+=c[x];return ans;}
void dfs(int u,int f){
    l[u]=++tot;
    int ecnt=e[u].size();
    for(int i=0;i<ecnt;++i){
        int v=e[u][i];
        if(v==f) continue;
        dfs(v,u);
    }
    r[u]=tot;
    printf("u:%d l:%d r:%d\n",u,l[u],r[u]);
}
int main(){
    int m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    for(int i=0;i<n-1;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(k,k);
    for(int i=1;i<=n;++i) add(l[i],a[i]);
    while(m--){
        int op,x,v;
        scanf("%d%d",&op,&x);
        if(op==1){
            scanf("%d",&v);
            add(l[x],v);
        }
        else{
            printf("%lld\n",sum(r[x])-sum(l[x]-1));
        }
    }
    return 0;
}