#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll mod=7777777;
int k,n;
struct matrix{
    ll m[12][12];
    matrix(){
        memset(m,0,sizeof(m));
    }
    ll *operator[](int x){
        return m[x];
    }
    matrix operator* (matrix &b){
        matrix r;
        for(int i=0;i<k;++i){
            for(int j=0;j<k;++j){
                for(int t=0;t<k;++t){
                    r.m[i][t]+=(m[i][j]*b.m[j][t])%mod;
                    r.m[i][t]%=mod;
                }
            }
        }
        return r;
    }
}a,t;
int main(){
    scanf("%d%d",&k,&n);
    a.m[0][0]=1;
    for(int i=1;i<k;++i) a.m[0][i]=a.m[0][i-1]<<1;
    for(int i=1;i<k;++i) t.m[i][i-1]=1;
    for(int i=0;i<k;++i) t.m[i][k-1]=1;
    if(n<k){
        if(n==1) puts("1");
        else printf("%lld\n",a.m[0][n-1]);
    }
    else{
        n=n-k;
        while(n){
            if(n&1) a=a*t;
            n>>=1;
            t=t*t;
        }
        printf("%lld\n",a.m[0][k-1]);
    }
}