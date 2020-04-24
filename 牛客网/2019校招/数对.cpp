#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int main(){
    int n,k;scanf("%d%d",&n,&k);
    if(k==0){
        printf("%lld\n",(ll)n*n);
        return 0;
    }
    ll ans=0;
    for(int i=k+1;i<=n;++i){
        ans+=(ll)(n/i)*(i-k)+max(0,n%i-k+1);
    }
    printf("%lld\n",ans);
    return 0;
}