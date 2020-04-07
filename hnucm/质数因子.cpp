#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
int main(){
    // freopen("data/factor2.in","r",stdin);
    // freopen("data/factor2.out","w",stdout);
    ll n;
    while(~scanf("%lld",&n)){
        for(ll i=2;i*i<=n;++i){
            if(n%i==0){
                while(n%i==0){
                    printf("%lld ",i);
                    n/=i;
                }
            }
        }
        if(n>1){
            printf("%lld ",n);
        }
        putchar('\n');
    }
    return 0;
}