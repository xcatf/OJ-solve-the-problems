#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int maxn=1e3+5;
int main(){
    int n;
    // freopen("data/table2.in","r",stdin);
    // freopen("data/table2.out","w",stdout);
    scanf("%d",&n);
    map<int,ll>mp;
    for(int i=0;i<n;++i){
        int k,v;
        scanf("%d%d",&k,&v);
        mp[k]+=v;
    }
    for(map<int,ll>::iterator it=mp.begin();it!=mp.end();++it) printf("%d %lld\n",it->first,it->second);
    return 0;
}