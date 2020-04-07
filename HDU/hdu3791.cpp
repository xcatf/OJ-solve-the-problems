#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=5e3+5;
char s1[15],s2[15];
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
bool check(Tree* rt,Tree* now){
    if(!rt&&!now) return true;
    if(!rt || !now) return false; 
    if(rt->val!=now->val) return false;
    int left=check(rt->l,now->l);
    int right=check(rt->r,now->r);
    return left&right;
}
int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        scanf("%s",s1);
        Tree *root=NULL;
        for(int i=0;s1[i];++i) build(root,s1[i]-'0');
        while(n--){
            scanf("%s",s2);
            Tree* now=NULL;
            for(int i=0;s2[i];++i) build(now,s2[i]-'0');
            printf("%s\n",check(root,now)?"YES":"NO");
        }
        delete root;
    }
    return 0;
}