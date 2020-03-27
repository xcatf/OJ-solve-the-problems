#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e6+5;
int main(){
    int n;
    scanf("%d",&n);
    ll ans=0;
    for(int i=1;i<=n;++i){
        int v;
        scanf("%d",&v);
        if(v>=0) ans+=v;
        else ans+=(ll)i*v;
    }
    printf("%lld\n",ans);
    return  0;
}