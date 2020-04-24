#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+5;
const int mod=1e9+3;
int c[11],ans[maxn];
int main(){
    int n,m;
    c[0]=1;
    for(int i=1;i<=9;++i) c[i]=c[i-1]<<1;
    ans[0]=1;
    for(int i=1;i<=1000;++i){
        for(int j=0;j<=9;++j){
            int now=i-c[j];
            if(now<0) break;
            ans[i]=(ans[i]+ans[now])%mod;
        }
    }
    scanf("%d",&m);
    while(m--){
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}