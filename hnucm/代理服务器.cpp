#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=5e3+5;
int n,m;
char p[1005][25],s[maxn][25];
int main(){
    // freopen("data/proxy4.in","r",stdin);
    // freopen("data/proxy4.out","w",stdout);
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;++i) scanf("%s",p[i]);
        scanf("%d",&m);
        for(int i=1;i<=m;++i) scanf("%s",s[i]);
        int now=1,ans=0,rmax;
        while(now<=m){
            rmax=0;
            for(int i=1;i<=n;++i){
                int j=now;
                while(strcmp(p[i],s[j]) && j<=m){
                    ++j;
                }
                rmax=max(j-now,rmax);
            }
            now+=rmax;
            if(rmax==0||now>m) break;
            ++ans;
        }
        if(rmax==0) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}