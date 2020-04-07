#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){ 
    ll n;
    int k;
    while(~scanf("%lld%d",&n,&k)){
        if(k==1){
            printf("%lld\n",n);
            continue;
        }
        ll ans=0;
        ll x=0;
        for(ll i=2;i<=n;i+=x){
            if(ans+k>=i) x=1;
            else{
                x=(i-ans-1)/(k-1);
                if((i-ans-1)%(k-1)==0) --x;
                if(i+x-1>=n) x=n-i+1;
            }
            ans=(ans+x*k)%(i+x-1);
        }
        printf("%lld\n",ans+1);
    }
    return 0;
}