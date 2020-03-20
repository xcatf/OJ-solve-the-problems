#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll maxn=1e18+5;
int main(){
    ll n;
    scanf("%lld",&n);
    ll l=2,r=3;
    bool fg=0;
    while(l<=n){
        if(n>=l&&n<=r){
            fg=1;
            break;
        }
        l=(l<<2)-1;
        r=(r<<2)+1;
    }
    puts(fg?"PIPI":"POPO");
    return 0;
}