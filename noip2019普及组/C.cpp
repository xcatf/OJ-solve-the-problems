#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
char s[maxn];
struct node{
    int l,r;
    char v;
};
node tr[maxn];
void build(int e,int l,int r){
    tr[e].l=l,tr[e].r=r;
    if(l==r){
        if(s[l]=='0'){
            tr[e].v='B';
        }else{
            tr[e].v='I';
        }
        return;
    }
    int mid=(l+r)>>1;
    build(e<<1,l,mid);
    build(e<<1|1,mid+1,r);
    if(tr[e<<1].v=='B'&&tr[e<<1|1].v=='B'){
        tr[e].v='B';
    }else if(tr[e<<1].v=='I'&&tr[e<<1|1].v=='I'){
        tr[e].v='I';
    }else{
        tr[e].v='F';
    }
}
void dfs(int e){
    //cout<<tr[e].l<<" "<<tr[e].r<<endl;
    if(tr[e].l<tr[e].r){
        dfs(e<<1);
        dfs(e<<1|1);   
    }
    printf("%c",tr[e].v);
}
int main(){
    // freopen("data/C5.in","r",stdin);
    // freopen("data/C5.out","w",stdout);
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    int ls=strlen(s+1);
    build(1,1,ls);
    dfs(1);
}