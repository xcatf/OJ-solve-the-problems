#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e6+5;
int main(){
    int n,c,val;
    scanf("%d%d",&n,&c);
    ll ans=0;
    int minl=INT_MAX;
    for(int i=1;i<=n;++i){
        scanf("%d",&val);
        ans+=val;
        minl=min(val,minl);
        if(i%c==0){
            ans-=minl;
            minl=INT_MAX;
        }
    }
    printf("%lld\n",ans);
    return 0;
}