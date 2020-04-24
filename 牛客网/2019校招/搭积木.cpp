#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
const int mod=1e9+3;
struct node{
    int w,l;
    bool operator<(const node&r)const{
        return w<r.w;
    }
}q[maxn];
int a[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d%d",&q[i].w,&q[i].l);
    sort(q,q+n);
    for(int i=1;i<=n;++i) a[i]=INT_MAX;
    int ans=0;
    for(int i=0;i<n;++i){
        int p=upper_bound(a+1,a+n+1,q[i].l)-a;
        ans=max(ans,p);
        a[p]=q[i].l;
    }
    printf("%d\n",ans);
    return 0;
}