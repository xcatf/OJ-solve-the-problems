#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
struct Tree{
    Tree* l;
    Tree* r;
    int val;
};
void build(Tree *&rt,int val){
    if(!rt){
        rt=new Tree();
        rt->val=val;
        return ;
    }
    if(val<rt->val) build(rt->l,val);
    else build(rt->r,val);
}
void preorder(Tree* rt){
    if(rt){
        printf("%d ",rt->val);
        preorder(rt->l);
        preorder(rt->r);
    }
}
void inorder(Tree* rt){
    if(rt){
        inorder(rt->l);
        printf("%d ",rt->val);
        inorder(rt->r);
    }
}
void posterorder(Tree* rt){
    if(rt){
        posterorder(rt->l);
        posterorder(rt->r);
        printf("%d ",rt->val);
    }
}
bool findTree(Tree* rt,int val){
    if(!rt) return false;
    if(rt->val>val) return findTree(rt->l,val);
    if(rt->val<val) return findTree(rt->r,val);
    return true;
}
int main(){
    int n;
    // freopen("data/bst0.in","r",stdin);
    // freopen("data/bst0.out","w",stdout);
    while(scanf("%d",&n)!=EOF){
        Tree* root=NULL;
        for(int i=0;i<n;++i){
            int v;
            scanf("%d",&v);
            if(findTree(root,v)) continue;
            build(root,v);
        }
        preorder(root);
        printf("\n");
        inorder(root);
        printf("\n");
        posterorder(root);
        printf("\n");
        delete root;
    }
    return 0;
}