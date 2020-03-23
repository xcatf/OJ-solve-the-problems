#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn = 1e5 + 5;
int main(){
    int n;
    scanf("%d",&n);
    map<int,int>m;
    int ans=0;
    for(int i=0;i<n;++i){
        int v;
        scanf("%d",&v);
        m[v]++;
        if(m[v]>m[ans]||m[v]==m[ans]&&v<ans) ans=v;
    }
    printf("%d\n",ans);
    return 0;
}