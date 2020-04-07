#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a,b;
    scanf("%lld%lld",&a,&b);
    ll ans=0;
    while(a>0&&b>0){
        if(a>b) swap(a,b);
        ll c=b/a;
        ans+=c*a;
        b-=c*a;
    }
    printf("%lld",ans);
    return 0;
}