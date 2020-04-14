#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
struct node{
    int a,b;
    bool operator<(const node &rhs)const{
        return a<rhs.a;
    }
}q[maxn];
int maxb[maxn];
int binary_max(int l,int r,int v){
    int ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(v>=q[mid].a){
            ans=max(ans,maxb[mid]);
            l=mid+1;
        }
        else r=mid-1;
        
    }
    return ans;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i) scanf("%d%d",&q[i].a,&q[i].b);
    sort(q,q+n);
    maxb[0]=q[0].b;
    for(int i=1;i<n;++i) maxb[i]=max(maxb[i-1],q[i].b);
    for(int i=0;i<m;++i){
        int v;
        scanf("%d",&v);
        printf("%d\n",binary_max(0,n-1,v));
    }
    return 0;
}