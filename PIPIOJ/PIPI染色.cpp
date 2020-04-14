#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int mod=1e9+7;
ll mul[maxn],sum[maxn];
void prework(){
    mul[0]=1;
    for(int i=1;i<maxn;++i){
        mul[i]=(mul[i-1]*i)%mod;
        sum[i]=(sum[i-1]+mul[i])%mod;
    }
}
int main(){
    int t;
    prework();
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        if(n<m) swap(n,m);
        ll ans=mul[n-m+1];
        for(int i=)
    }
    return 0;
}