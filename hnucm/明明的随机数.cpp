#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
int main(){
    // freopen("data/randnum3.in","r",stdin);
    // freopen("data/randnum3.out","w",stdout);
    int n;
    while(~scanf("%d",&n)){
        set<int>se;
        for(int i=0;i<n;++i){
            int v;
            scanf("%d",&v);
            se.emplace(v);
        }
        for(set<int>::iterator it=se.begin();it!=se.end();++it) printf("%d\n",*it);
    }
    return 0;
}