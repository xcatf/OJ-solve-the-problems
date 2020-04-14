#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    ll ans=0;
    if(k==0){
        ans+=(ll)n*n;
        printf("%lld\n",ans);
        return 0;
    }
    ans+=n-k;
    for(int i=k+1;i<=n;++i){
        ans+=n-i;
        int cnt=i*2-i+k;
        while(cnt<=n){
            if(cnt+i-k-1<=n) ans+=i-k;
             else ans+=n-cnt+1;

            cnt+=i;
        }
    }
    printf("%lld\n",ans);
    return 0;
}