#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const ll mod=7777777;
struct Tree{
    Tree* l;
    Tree* r;
    char val;
    Tree(){
        l=NULL;
        r=NULL;
    }
};
char s[205];
Tree* build(int l,int r){
    Tree* now=new Tree();
    if(l==r){
        now->val=(s[l]=='1')?'I':'B';
        return now;
    }
    int m=(l+r)>>1;
    now->l=build(l,m);
    now->r=build(m+1,r);
    now->val=now->l->val=='B'&&now->r->val=='B'?'B':now->l->val=='I'&&now->r->val=='I'?'I':'F';
    return now;

}
void traversal(Tree *rt){   
    if(rt){
        traversal(rt->l);
        traversal(rt->r);
        printf("%c",rt->val);
    }
}
int main(){
    Tree* root=new Tree();
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    n=n<<1;
    root=build(1,n);
    traversal(root);
    return 0;
}