#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e4+5;
bool vis[maxn];
bool fail[maxn];
int cnt[maxn];
bool prime(int x){
    if(x==1) return false;
    if(x==2||x==3) return true;
    if(x%6!=1&&x%6!=5) return false;
    for(int i=5;i*i<=x;i+=6){
        if(x%i==0||x%(i+2)==0) return false;
    }
    return true;
}
int getpow(int x){
    int ans=0;
    while(x){
        ans+=(x%10)*(x%10);
        x/=10;
    }
    return ans;
}
int l,r;
int dfs(int now){
    int cnt=0;
    int t=now;
    memset(vis,0,sizeof(vis));
    while(now!=1){
        if(vis[now]){
            cnt=0;
            break;
        }
        vis[now]=1;
        now=getpow(now);
        fail[now]=1;
        ++cnt;
    }
    if(cnt==0) fail[t]=1;
    return cnt;
}
int main(){
    scanf("%d%d",&l,&r);
    bool fg=0;
    for(int i=l;i<=r;++i){
        int r=dfs(i);
        cnt[i]=prime(i)?r*2:r;
    }
    for(int i=l;i<=r;++i){
        if(fail[i]) continue;
        printf("%d %d\n",i,cnt[i]);
        fg=1;  
    }
    if(!fg) puts("SAD");
    return 0;
}