#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
struct node{
    int a,b;
    bool operator<(const node&rhs)const{
        return a<rhs.a;
    }
}q[maxn];
int r[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i) r[i]=INT_MAX;
    for(int i=0;i<n;++i) scanf("%d%d",&q[i].a,&q[i].b);
    sort(q,q+n);
    for(int i=0;i<n;++i){
        int p=upper_bound(r,r+n,q[i].b)-r;
        
    }
    return 0;
}