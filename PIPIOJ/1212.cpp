#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=(1<<22);
int n,m,cnt;
int a[maxn];
bool b[maxn],v[maxn];
void dfs(int now){
    v[now]=1;
    for(int i=0;i<n;++i){
        if(((1<<i)&now)==0&&!v[now|(1<<i)]) dfs(now|(1<<i));
    }
    if(b[cnt^now]&&!v[cnt^now]) dfs(cnt^now);
}
void solve(int &ans){
    for(int i=0;i<m;++i){
        if(!v[cnt^a[i]]){   //这个点构成独立块
            ++ans;
            dfs(a[i]);    
        }
    }
}
int main(){ 
    while(~scanf("%d%d",&n,&m)){
        memset(v,0,sizeof(v));
        memset(b,0,sizeof(b));
        for(int i=0;i<m;++i) scanf("%d",&a[i]),b[a[i]]=1;
        int ans=0;
        cnt=(1<<n)-1;
        solve(ans);
        printf("%d\n",ans);
    }
    return 0;
}