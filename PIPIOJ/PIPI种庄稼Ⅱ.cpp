#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5 + 5;
int sum[maxn];
struct node{
    int l,r,w;
    bool operator<(const node&rhs)const{
        return l<rhs.l;
    }
}q[maxn];
struct interval{
    int l,r;
}p[maxn];
map<int,int>mp;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i) scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].w);
    sort(q+1,q+m+1);
    int cnt=0;
    for(int i=1;i<=m;++i){
        int w=q[i].w;
        if(!mp[w]) mp[w]=++cnt;
        w=mp[w];
        int ql=p[w].l;
        int qr=p[w].r;
        if(ql<=q[i].l&&qr>=q[i].r) continue;    //此区间被完全种过庄稼w
        if(q[i].l>qr){  //此区间第一次种庄稼w
            sum[q[i].l]++;
            sum[q[i].r+1]--;
            p[w].l=q[i].l;
            p[w].r=q[i].r;
        }
        else{           //此区间有部分种过庄稼w
            sum[p[w].r+1]++;
            sum[q[i].r+1]--;
            p[w].r=q[i].r;
        }
    }
    int r=0;
    for(int i=1;i<=n;++i){
        sum[i]+=sum[i-1];
        if(sum[r]<sum[i]) r=i;
    }
    printf("%d\n",r);
    return 0;
}