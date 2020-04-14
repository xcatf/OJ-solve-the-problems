#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e5+5;
int p[maxn];
int main(){
    int n,m,v;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&v);
        p[i]=p[i-1]+v;
    }
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d",&v);
        int pos=lower_bound(p+1,p+n+1,v)-p;
        printf("%d\n",pos);      
    }
    return 0;
}