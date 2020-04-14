#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    ll ans=0;
    for(int i=k+1;i<=n;++i){
        ans+=(n/i)*(i-k);
        if(n%i>=k){
            if(k) ans+=n%i-k+1;
            else ans+=n%i;
        }
    }
    printf("%lld\n",ans);
    return 0;
}