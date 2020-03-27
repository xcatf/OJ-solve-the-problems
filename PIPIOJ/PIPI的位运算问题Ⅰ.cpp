#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5 + 5;
int main(){
    ll L,R;
    scanf("%lld%lld",&L,&R);
    if(L>R) swap(L,R);
    ll t=1,ans=0;
    while(R){
        if((L&1)&(R&1)){}
        else ans+=t;
        t<<=1;
        R>>=1;
        L>>=1;
    }
    printf("%lld\n",ans);
    return 0;
}