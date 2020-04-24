#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int cnt[32];
int main(){
    int n,v;
    scanf("%d",&n);
    int x=0;
    for(int i=0;i<n;++i){
        scanf("%d",&v);
        x^=v;
        for(int j=0;j<32;++j) cnt[j]+=(x>>j)&1;
    }
    ll ans=0;
    for(int i=0;i<32;++i){
        ans+=(ll)cnt[i]*((n+1-cnt[i])<<i);
    }
    printf("%lld\n",ans);
    return 0;
}