#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
int a[maxn],t[maxn],p[maxn];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    for(int i=1;i<=n;++i) scanf("%d",&t[i]);
    int ans=0;
    for(int i=1;i<=n;++i){
        p[i]=p[i-1]+(t[i]==1?0:a[i]);
        if(i>=k) ans=max(ans,p[i]-p[i-k]);
    }
    for(int i=1;i<=n;++i) ans+=t[i]==1?a[i]:0;
    printf("%d\n",ans);
    return 0;
}