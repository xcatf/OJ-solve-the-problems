#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
int cnt[maxn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int ans=INT_MAX;
    for(int i=0;i<m;++i){
        int c;
        scanf("%d",&c);
        cnt[c]++;
    }
    for(int i=1;i<=n;++i){
        ans=min(cnt[i],ans);
    }
    printf("%d\n",ans);
    return 0;
}