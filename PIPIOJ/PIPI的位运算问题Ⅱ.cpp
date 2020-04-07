#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5 + 5;
int main(){
    ll l,r;
    while(~scanf("%lld%lld",&l,&r)){
        if(l>r) swap(l,r);
        ll ans=0;
        if(l&1){
            for(ll i=l;l<=i+4&&l<=r;++l) ans^=l;
        }
        else{
            for(ll i=l;l<=i+3&&l<=r;++l) ans^=l;
        }
        if(r<l){
            printf("%lld\n",ans);
            continue;
        }
        l=l+(r-l+1)/4*4;
        for(ll i=l;i<=r;++i) ans^=i;
        printf("%lld\n",ans);
    }
    return 0;
}