#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int N=1e5+5;
int rt[N*50],ls[N*50],rs[N*50],cnt,n;
int val[N*50],ans1[N],ans2[N],c[N],mp[N];
int low(int x){return x&-x;}
void add(int x){for(;x<=n;x+=low(x)) c[x]++;}
int sum(int x){int ans=0;for(;x;x-=low(x)) ans+=c[x];return ans;}
void update(int &now,int l,int r,int p){
    if(!now) now=++cnt;
    val[now]++;
    if(l==r-1) return ;
    int mid=(l+r)>>1;
    if(p<mid) update(ls[now],l,mid,p);
    else update(rs[now],mid,r,p);
}
int query(int now,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r-1) return val[now];
    int ans=0;
    int mid=(l+r)>>1;
    if(ql<mid) ans+=query(ls[now],l,mid,ql,qr);
    if(qr>=mid) ans+=query(rs[now],mid,r,ql,qr);
    return ans;
}
int ask(int l,int r,int ql,int qr){
    if(ql>qr) return 0;
    int ans=0;
    for(int i=l;i;i-=low(i)) ans-=query(rt[i],1,n+1,ql,qr);
    for(int i=r;i;i-=low(i)) ans+=query(rt[i],1,n+1,ql,qr);
    return ans;
}
int main(){
    int m,x;
    scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&x);
        mp[x]=i;
        ans1[i]=sum(n)-sum(x);  //左边大于x的数
        ans2[i]=x-sum(x)-1;     //右边小于x的数
        ans+=ans1[i];
        add(x);
    }
    for(int i=0;i<m;++i){
        scanf("%d",&x);
        printf("%d\n",ans);
        int pos=mp[x];
        ans-=(ans1[pos]+ans2[pos])-ask(0,pos,x+1,n)-ask(pos,n,1,x-1);
        for(int j=pos;j<=n;j+=low(j)) update(rt[j],1,n+1,x);
    }
    return 0;
}