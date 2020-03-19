#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
int s[maxn];
int main(){
    // freopen("data/D1.in","r",stdin);
    // freopen("data/D1.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&s[i]);
    }
    while(m--){
        next_permutation(s+1,s+n+1);
    }
    for(int i=1;i<=n;++i){
        printf("%d%c",s[i],i==n?'\n':' ');
    }
}