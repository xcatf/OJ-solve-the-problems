#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e2 + 5;
typedef long long ll;
struct Tree{
    Tree *left;
    Tree *right;
    int val;
};
int p[35], in[35];
int cnt;
void build(Tree *&rt, int l, int r){
    if(l > r) return ;
    rt = new Tree();
    int nval = p[cnt++];
    rt->val = nval;
    int pos = find(in + 1, in + r + 1, nval) - in;
    build(rt->left, l, pos - 1);
    build(rt->right, pos + 1, r);
}
void bfs(Tree *rt){
    queue<Tree*>q;
    q.push(rt);
    while(!q.empty()){
        Tree *now = q.front();
        q.pop();
        if(now != rt) putchar(' ');
        printf("%d", now->val);
        if(now){
            if(now->right) q.push(now->right);
            if(now->left) q.push(now->left);
        }
    }
    putchar('\n');
}
int main()
{   
    Tree *root;
    int n;
    scanf("%d", &n); 
    for(int i = 1; i <= n; ++i) scanf("%d", &in[i]);
    for(int i = 1; i <= n; ++i) scanf("%d", &p[i]);
    cnt = 1;
    build(root, 1, n);
    bfs(root);
    return 0;
}