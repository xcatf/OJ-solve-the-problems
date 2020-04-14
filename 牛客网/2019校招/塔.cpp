#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e2+5;
struct node{
    int l,r,id1,id2;
    int min,max;
}tr[maxn<<2];
struct ask{
    int x,y;
    ask(){}
    ask(int _x,int _y):x(_x),y(_y){}
};
void pushUp(int now){
    if(tr[now<<1].max>=tr[now<<1|1].max){
        tr[now].max=tr[now<<1].max;
        tr[now].id1=tr[now<<1].id1;
    }
    else{
        tr[now].max=tr[now<<1|1].max;
        tr[now].id1=tr[now<<1|1].id1;
    }
    if(tr[now<<1].min<=tr[now<<1|1].min){
        tr[now].min=tr[now<<1].min;
        tr[now].id2=tr[now<<1].id2;
    }
    else{
        tr[now].min=tr[now<<1|1].min;
        tr[now].id2=tr[now<<1|1].id2;
    }
}
void build(int now,int l,int r){
    tr[now].l=l;
    tr[now].r=r;
    if(l==r){
        scanf("%d",&tr[now].max);
        tr[now].min=tr[now].max;
        tr[now].id1=tr[now].id2=l;
        return ;
    }
    int mid=(l+r)>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    pushUp(now);
}
ask seq[1005];
ask query_max(int now,int ql,int qr){
    if(ql==tr[now].l&&qr==tr[now].r){
        return ask(tr[now].id1,tr[now].max);
    }
    int mid=(tr[now].l+tr[now].r)>>1;
    if(qr<=mid) return query_max(now<<1,ql,qr);
    if(ql>=mid) return query_max(now<<1|1,ql,qr);

    ask left=query_max(now<<1,ql,mid);
    ask right=query_max(now<<1|1,mid+1,qr);
    return left.y>=right.y?left:right;
}
ask query_min(int now,int ql,int qr){
    if(ql==tr[now].l&&qr==tr[now].r){
        return ask(tr[now].id2,tr[now].min);
    }
    int mid=(tr[now].l+tr[now].r)>>1;
    if(qr<=mid) return query_min(now<<1,ql,qr);
    if(ql>=mid) return query_min(now<<1|1,ql,qr);

    ask left=query_min(now<<1,ql,mid);
    ask right=query_min(now<<1|1,mid+1,qr);
    return left.y<=right.y?left:right;
}
void update(int now,int pos,int v){
    if(tr[now].l==tr[now].r){
        tr[now].max+=v;
        tr[now].min+=v;
        return ;
    }
    if(tr[now<<1].r>=pos) update(now<<1,pos,v);
    else update(now<<1|1,pos,v);
    pushUp(now);
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    build(1,1,n);
    int cnt=0;
    for(int i=0;i<k;++i){
        ask r1=query_max(1,1,n);
        ask r2=query_min(1,1,n);
        if(r1.y==r2.y) break;
        seq[++cnt].x=r1.x;
        seq[cnt].y=r2.x;
        update(1,r1.x,-1);
        update(1,r2.x,1);
    }
    printf("%d %d\n",query_max(1,1,n).y-query_min(1,1,n).y,cnt);
    for(int i=1;i<=cnt;++i) printf("%d %d\n",seq[i].x,seq[i].y);
    return 0;
}