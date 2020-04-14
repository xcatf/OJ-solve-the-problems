#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int mod=1e9+7;
int main(){
    ll n,v;
    int m;
    scanf("%lld%d",&n,&m);
    ll ans=0;
    for(int i=0;i<m;++i){
        scanf("%lld",&v);
        ans^=v;
    }
    printf("%lld\n",ans);
    return 0;
}