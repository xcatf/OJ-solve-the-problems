#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e6+5;
typedef long long ll;
int n;
int c[maxn], a[maxn];
ll cnt[maxn];
int lowbit(int x){
    return x&-x;
}
void update(int x, int v){
    for(int i=x; i<maxn; i+=lowbit(i)){
        c[i]+=v;
    }
}
int getsum(int x){
    int res=0;
    for(int i=x; i; i-=lowbit(i)){
        res+=c[i];
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        scanf("%d",&a[i]);
        update(a[i]+1,1);   //a[i]+1是因为这里的小朋友身高从0开始，而树状数组下标从1开始
        cnt[i]=i-getsum(a[i]+1);
    }
    memset(c,0,sizeof(c));
    ll ans=0;
    for(int i=n; i>=1; --i){
        update(a[i]+1,1);
        cnt[i]+=getsum(a[i]);
        ans+=(1+cnt[i])*cnt[i]/2;
    }
    printf("%lld\n",ans);
    return 0;
}