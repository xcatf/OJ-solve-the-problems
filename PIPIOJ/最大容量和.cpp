#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int n,k,L;
int a[maxn];
int main(){
    scanf("%d%d%d",&n,&k,&L);
    int N=n*k;
    for(int i=0;i<N;++i) scanf("%d",&a[i]);
    sort(a,a+N);
    int pos=upper_bound(a,a+N,a[0]+L)-a;
    int cnt=N-pos;
    ll ans=0;
    for(int i=pos-1;i>=0;--i){
        ++cnt;
        if(cnt>=k){
            cnt-=k;
            ans+=a[i];
        }
    }
    if(cnt) puts("0");
    else printf("%lld\n",ans);
    return 0;
}