#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5 + 5;
int main(){
    ll L,R;
    scanf("%lld%lld",&L,&R);
    if(L>R) swap(L,R);
    ll ans=0;
    bool f=0;
    for(int i=60;i>=0;--i){
        ll d=1ll<<i;
        if(d>R) continue;
        int r=(R>>i)&1;
        int l=(L>>i)&1;
        if(r!=l) ans+=d;
        else if(r==0) ans+=d,f=1;
        else if(f) ans+=d;
    }
    printf("%lld\n",ans);
    return 0;
}