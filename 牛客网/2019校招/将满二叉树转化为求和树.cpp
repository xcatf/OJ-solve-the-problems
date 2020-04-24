#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int in[maxn];
struct bitree{
    bitree *lc,*rc;
    int data1,data2;
};
void build(bitree*&rt,int l,int r){
    if(l>r){
        rt=NULL;
        return ;
    }
    int mid=(l+r)>>1;
    rt=new bitree();
    rt->data1=in[mid];
    build(rt->lc,l,mid-1);
    build(rt->rc,mid+1,r);
}
void getsum(bitree* &rt){
    if(!rt->lc){
        rt->data2=0;
        return ;
    }
    getsum(rt->lc);
    getsum(rt->rc);
    rt->data2=rt->lc->data2+rt->lc->data1+rt->rc->data2+rt->rc->data1;
}
void inorder(bitree* rt){
    if(rt){
        inorder(rt->lc);
        printf("%d ",rt->data2);
        inorder(rt->rc);
    }
}
int main(){
    int n;
    do{
        scanf("%d",&n);
    }while(getchar()!='\n');
    n=1;
    do{
        scanf("%d",&in[n++]);
    }while(getchar()!='\n');
    --n;
    bitree* rt=NULL;
    build(rt,1,n);
    getsum(rt);
    inorder(rt);
    return 0;
}